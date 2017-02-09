#include <vector>

#include "caffe/filler.hpp"
#include "caffe/layer.hpp"
#include "caffe/util/im2col.hpp"
#include "caffe/util/math_functions.hpp"
#include "caffe/vision_layers.hpp"
#include "caffe/util/benchmark.hpp"
#include "caffe/gustavson.hpp"

namespace caffe {

template <typename Dtype>
void BaseConvolutionLayer<Dtype>::LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
  CHECK_EQ(4, bottom[0]->num_axes()) << "Input must have 4 axes, "
      << "corresponding to (num, channels, height, width)";
  // Configure the kernel size, padding, stride, and inputs.
  ConvolutionParameter conv_param = this->layer_param_.convolution_param();
  CHECK(!conv_param.has_kernel_size() !=
      !(conv_param.has_kernel_h() && conv_param.has_kernel_w()))
      << "Filter size is kernel_size OR kernel_h and kernel_w; not both";
  CHECK(conv_param.has_kernel_size() ||
      (conv_param.has_kernel_h() && conv_param.has_kernel_w()))
      << "For non-square filters both kernel_h and kernel_w are required.";
  CHECK((!conv_param.has_pad() && conv_param.has_pad_h()
      && conv_param.has_pad_w())
      || (!conv_param.has_pad_h() && !conv_param.has_pad_w()))
      << "pad is pad OR pad_h and pad_w are required.";
  CHECK((!conv_param.has_stride() && conv_param.has_stride_h()
      && conv_param.has_stride_w())
      || (!conv_param.has_stride_h() && !conv_param.has_stride_w()))
      << "Stride is stride OR stride_h and stride_w are required.";
  if (conv_param.has_kernel_size()) {
    kernel_h_ = kernel_w_ = conv_param.kernel_size();
  } else {
    kernel_h_ = conv_param.kernel_h();
    kernel_w_ = conv_param.kernel_w();
  }
  CHECK_GT(kernel_h_, 0) << "Filter dimensions cannot be zero.";
  CHECK_GT(kernel_w_, 0) << "Filter dimensions cannot be zero.";
  if (!conv_param.has_pad_h()) {
    pad_h_ = pad_w_ = conv_param.pad();
  } else {
    pad_h_ = conv_param.pad_h();
    pad_w_ = conv_param.pad_w();
  }
  if (!conv_param.has_stride_h()) {
    stride_h_ = stride_w_ = conv_param.stride();
  } else {
    stride_h_ = conv_param.stride_h();
    stride_w_ = conv_param.stride_w();
  }
  // Special case: im2col is the identity for 1x1 convolution with stride 1
  // and no padding, so flag for skipping the buffer and transformation.
  is_1x1_ = kernel_w_ == 1 && kernel_h_ == 1
      && stride_h_ == 1 && stride_w_ == 1 && pad_h_ == 0 && pad_w_ == 0;
  // Configure output channels and groups.
  channels_ = bottom[0]->channels();
  num_output_ = this->layer_param_.convolution_param().num_output();
  CHECK_GT(num_output_, 0);
  group_ = this->layer_param_.convolution_param().group();
  CHECK_EQ(channels_ % group_, 0);
  CHECK_EQ(num_output_ % group_, 0)
      << "Number of output should be multiples of group.";
  if (reverse_dimensions()) {
    conv_out_channels_ = channels_;
    conv_in_channels_ = num_output_;
  } else {
    conv_out_channels_ = num_output_;
    conv_in_channels_ = channels_;
  }
  // Handle the parameters: weights and biases.
  // - blobs_[0] holds the filter weights
  // - blobs_[1] holds the biases (optional)
  bias_term_ = this->layer_param_.convolution_param().bias_term();
  if (this->blobs_.size() > 0) {
    LOG(INFO) << "Skipping parameter initialization";
  } else {
    if (bias_term_) {
      this->blobs_.resize(2);
    } else {
      this->blobs_.resize(1);
    }
    // Initialize and fill the weights:
    // output channels x input channels per-group x kernel height x kernel width
    this->blobs_[0].reset(new Blob<Dtype>(
        conv_out_channels_, conv_in_channels_ / group_, kernel_h_, kernel_w_));
    shared_ptr<Filler<Dtype> > weight_filler(GetFiller<Dtype>(
        this->layer_param_.convolution_param().weight_filler()));
    weight_filler->Fill(this->blobs_[0].get());
    // If necessary, initialize and fill the biases.
    if (bias_term_) {
      vector<int> bias_shape(1, num_output_);
      this->blobs_[1].reset(new Blob<Dtype>(bias_shape));
      shared_ptr<Filler<Dtype> > bias_filler(GetFiller<Dtype>(
          this->layer_param_.convolution_param().bias_filler()));
      bias_filler->Fill(this->blobs_[1].get());
    }
  }
  // Propagate gradients to the parameters (as directed by backward pass).
  this->param_propagate_down_.resize(this->blobs_.size(), true);
}

template <typename Dtype>
void BaseConvolutionLayer<Dtype>::Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
  CHECK_EQ(4, bottom[0]->num_axes()) << "Input must have 4 axes, "
      << "corresponding to (num, channels, height, width)";
  num_ = bottom[0]->num();
  height_ = bottom[0]->height();
  width_ = bottom[0]->width();
  CHECK_EQ(bottom[0]->channels(), channels_) << "Input size incompatible with"
    " convolution kernel.";
  // TODO: generalize to handle inputs of different shapes.
  for (int bottom_id = 1; bottom_id < bottom.size(); ++bottom_id) {
    CHECK_EQ(num_, bottom[bottom_id]->num()) << "Inputs must have same num.";
    CHECK_EQ(channels_, bottom[bottom_id]->channels())
        << "Inputs must have same channels.";
    CHECK_EQ(height_, bottom[bottom_id]->height())
        << "Inputs must have same height.";
    CHECK_EQ(width_, bottom[bottom_id]->width())
        << "Inputs must have same width.";
  }
  // Shape the tops.
  compute_output_shape();
  for (int top_id = 0; top_id < top.size(); ++top_id) {
    top[top_id]->Reshape(num_, num_output_, height_out_, width_out_);
  }
  if (reverse_dimensions()) {
    conv_in_height_ = height_out_;
    conv_in_width_ = width_out_;
    conv_out_spatial_dim_ = height_ * width_;
  } else {
    conv_in_height_ = height_;
    conv_in_width_ = width_;
    conv_out_spatial_dim_ = height_out_ * width_out_;
  }
  kernel_dim_ = conv_in_channels_ * kernel_h_ * kernel_w_;
  weight_offset_ = conv_out_channels_ * kernel_dim_ / group_ / group_;
  col_offset_ = kernel_dim_ * conv_out_spatial_dim_ / group_;
  output_offset_ = conv_out_channels_ * conv_out_spatial_dim_ / group_;
  // The im2col result buffer will only hold one image at a time to avoid
  // overly large memory usage. In the special case of 1x1 convolution
  // it goes lazily unused to save memory.
  if (reverse_dimensions()) {
    col_buffer_.Reshape(1, kernel_dim_, height_, width_);
  } else {
    col_buffer_.Reshape(1, kernel_dim_, height_out_, width_out_);
  }
  // Set up the all ones "bias multiplier" for adding biases by BLAS
  if (bias_term_) {
    vector<int> bias_multiplier_shape(1, height_out_ * width_out_);
    bias_multiplier_.Reshape(bias_multiplier_shape);
    caffe_set(bias_multiplier_.count(), Dtype(1),
        bias_multiplier_.mutable_cpu_data());
  }
}

template <typename Dtype>
inline void gustavson(
	const Dtype * __restrict__ kernel, 
	const int kernel_offset, 
	const int kernel_size_x,
	const int kernel_size_y,
	const Dtype * __restrict__ image, 
	const int image_offset, 
	const int image_size_x,
	const int image_size_y,
	Dtype * __restrict__ result,
	const int result_offset,
	const int result_size_x,
	const int result_size_y
) {
	
  std::vector<Dtype> nonZeroValues;
  std::vector<int> indicesX;
  std::vector<int> indicesY;
  caffe::convertKernelToCompressed(kernel, kernel_size_x, kernel_size_y, nonZeroValues, indicesX, indicesY);
  caffe::CPUTimer timer;
   timer.Start();
  
  gustavsonCompressed(&nonZeroValues[0], &indicesX[0], &indicesY[0], nonZeroValues.size(), image, image_size_x, image_size_y, result, result_size_x, result_size_y);
 timer.Stop();
  LOG(INFO) << "cconv calculus microseconds = " << timer.MicroSeconds();

/*
	// zerofill result
	for (int i = 0; i < result_size_y; i++) {
		for (int j = 0; j < result_size_x; j++) {
			result[i * result_offset + j] = 0;
		}
	}
	
	for (int kernel_line = 0; kernel_line < kernel_size_y; kernel_line++) {
		for (int kernel_col = 0; kernel_col < kernel_size_x; kernel_col++) {
			float mult = kernel[kernel_line * kernel_offset + kernel_col];
			if (std::abs(mult) > 1e-8) {
				int image_line = kernel_col;
				
				const int res_off = kernel_line * result_offset;
				const int img_off = image_line * image_offset; 
				#pragma GCC ivdep
				for (int image_col = 0; image_col < image_size_x; image_col++) {
					result[res_off + image_col] += mult * image[img_off + image_col];
				}
			}
		}
	}
*/
}

template <typename Dtype>
inline void naive(
	const Dtype * __restrict__ kernel, 
	const int kernel_offset, 
	const int kernel_size_x,
	const int kernel_size_y,
	const Dtype * __restrict__ image, 
	const int image_offset, 
	const int image_size_x,
	const int image_size_y,
	Dtype * __restrict__ result,
	const int result_offset,
	const int result_size_x,
	const int result_size_y
) {
	for (int i = 0; i < result_size_y; i++) {
		for (int j = 0; j < result_size_x; j++) {
			result[i * result_offset + j] = 0;
			for (int k = 0; k < kernel_size_x; k++) {
				result[i * result_offset + j] += kernel[i * kernel_offset + k] * image[k * image_offset + j];
			}
		}
	}
}

template <typename Dtype>
inline void gustavsonGEMM(
	const Dtype *kernel, 
	const int kernel_offset, 
	const int kernel_size_x,
	const int kernel_size_y,
	const Dtype *image, 
	const int image_offset, 
	const int image_size_x,
	Dtype *result,
	const int result_offset
) {
	gustavson(
		kernel, 
		kernel_offset, 
		kernel_size_x, 
		kernel_size_y, 
		image, 
		image_offset, 
		image_size_x, 
		kernel_size_x, 
		result, 
		result_offset, 
		image_size_x, 
		kernel_size_y
	);
}


template <typename Dtype>
void BaseConvolutionLayer<Dtype>::forward_cpu_sparse_gemm(
	const Dtype* input, 
	const Dtype* weightsCompressed, 
	const int *indicesX, 
	const int *indicesY, 
	const int sizeNonZeroWeights, 
	Dtype *output, 
	bool skip_im2col
) 
{
	//caffe::CPUTimer timer;
	//timer.Start();
		 
	const Dtype* col_buff = input;
	  if (!is_1x1_) {
		if (!skip_im2col) {
		  conv_im2col_cpu(input, col_buffer_.mutable_cpu_data());
		}
		col_buff = col_buffer_.cpu_data();
	  }
  
	//timer.Stop();
	//LOG(INFO) << "im2col calculus microseconds = " << timer.MicroSeconds();
  
    caffe::gustavsonCompressed(
		weightsCompressed, 
		indicesX, 
		indicesY, 
		sizeNonZeroWeights, 
		col_buff, 
		conv_out_spatial_dim_, 
		conv_out_channels_, 
		output, 
		conv_out_spatial_dim_,
		conv_out_channels_
	);
}


template <typename Dtype>
void BaseConvolutionLayer<Dtype>::forward_cpu_sparse_conv(
	const Dtype* input, 
	const Dtype* weightCompressed, 
	const int* indicesX, 
	const int* indicesRow, 
	const int sizeNonZeroWeights, 
	Dtype *output
) {
//	LOG(INFO)<< "Running direct convolution with kernel (" << this->kernel_w_ << ", " << this->kernel_h_ << ")";
//	LOG(INFO)<< "Image size (" << this->width_ << ", " << this->height_ << ")";
//	LOG(INFO)<< "Output size (" << this->width_out_ << ", " << height_out_ << ")";
//	LOG(INFO)<< "Channels: input=" << this->channels_ << ", output=" << this->num_output_;
//	LOG(INFO)<< "Pad w = " << this->pad_w_ << ", pad h = " << this->pad_h_; 
	
	caffe::directConvolution2(
		weightCompressed,
		indicesX,
		indicesRow,
		sizeNonZeroWeights,
		
		this->kernel_w_,
		this->kernel_h_,
		
		input,
		this->channels_,
		this->width_,
		this->height_,
		
		output,
		this->num_output_,
		this->width_out_,
		this->height_out_
	);
}


template <typename Dtype>
void BaseConvolutionLayer<Dtype>::forward_cpu_sparse_conv_ch(
	const Dtype* input, 
	const Dtype* weightCompressed, 
	const int* indicesX, 
	const int* indicesChannel,
	const int* indicesRow, 
	const int sizeNonZeroWeights, 
	Dtype *output
) {
//	LOG(INFO)<< "Running direct convolution with kernel (" << this->kernel_w_ << ", " << this->kernel_h_ << ")";
//	LOG(INFO)<< "Image size (" << this->width_ << ", " << this->height_ << ")";
//	LOG(INFO)<< "Output size (" << this->width_out_ << ", " << height_out_ << ")";
//	LOG(INFO)<< "Channels: input=" << this->channels_ << ", output=" << this->num_output_;
//	LOG(INFO)<< "Pad w = " << this->pad_w_ << ", pad h = " << this->pad_h_; 
	
	caffe::directConvolutionCenteredEx2(
		weightCompressed,
		indicesX,
		indicesChannel,
		indicesRow,
		sizeNonZeroWeights,
		
		this->kernel_w_,
		this->kernel_h_,
		
		input,
		this->channels_,
		this->width_,
		this->height_,
		
		output,
		this->num_output_,
		this->width_out_,
		this->height_out_
	);
}
		


template <typename Dtype>
void BaseConvolutionLayer<Dtype>::forward_cpu_gemm(const Dtype* input,
    const Dtype* weights, Dtype* output, bool skip_im2col) {
  const Dtype* col_buff = input;
  if (!is_1x1_) {
    if (!skip_im2col) {
      conv_im2col_cpu(input, col_buffer_.mutable_cpu_data());
    }
    col_buff = col_buffer_.cpu_data();
  }
  /*
    
    gustavsonGEMM(
		weights, 
		kernel_dim_, 
		kernel_dim_, 
		conv_out_channels_, 

		col_buff, 
		conv_out_spatial_dim_, 
		conv_out_spatial_dim_, 
		
		output,
		conv_out_spatial_dim_
	);
  
*/
     
  for (int g = 0; g < group_; ++g) {
// (50, 64, 500, ..)
    caffe_cpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, conv_out_channels_ /
        group_, conv_out_spatial_dim_, kernel_dim_ / group_,
        (Dtype)1., weights + weight_offset_ * g, col_buff + col_offset_ * g,
        (Dtype)0.,  output + output_offset_ * g);
  }
 }

template <typename Dtype>
void BaseConvolutionLayer<Dtype>::forward_cpu_bias(Dtype* output,
    const Dtype* bias) {
  caffe_cpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, num_output_,
      height_out_ * width_out_, 1, (Dtype)1., bias, bias_multiplier_.cpu_data(),
      (Dtype)1., output);
}

template <typename Dtype>
void BaseConvolutionLayer<Dtype>::backward_cpu_gemm(const Dtype* output,
    const Dtype* weights, Dtype* input) {
  Dtype* col_buff = col_buffer_.mutable_cpu_data();
  if (is_1x1_) {
    col_buff = input;
  }
  for (int g = 0; g < group_; ++g) {
    caffe_cpu_gemm<Dtype>(CblasTrans, CblasNoTrans, kernel_dim_ / group_,
        conv_out_spatial_dim_, conv_out_channels_ / group_,
        (Dtype)1., weights + weight_offset_ * g, output + output_offset_ * g,
        (Dtype)0., col_buff + col_offset_ * g);
  }
  if (!is_1x1_) {
    conv_col2im_cpu(col_buff, input);
  }
}

template <typename Dtype>
void BaseConvolutionLayer<Dtype>::weight_cpu_gemm(const Dtype* input,
    const Dtype* output, Dtype* weights) {
  const Dtype* col_buff = input;
  if (!is_1x1_) {
    conv_im2col_cpu(input, col_buffer_.mutable_cpu_data());
    col_buff = col_buffer_.cpu_data();
  }
  for (int g = 0; g < group_; ++g) {
    caffe_cpu_gemm<Dtype>(CblasNoTrans, CblasTrans, conv_out_channels_ / group_,
        kernel_dim_ / group_, conv_out_spatial_dim_,
        (Dtype)1., output + output_offset_ * g, col_buff + col_offset_ * g,
        (Dtype)1., weights + weight_offset_ * g);
  }
}

template <typename Dtype>
void BaseConvolutionLayer<Dtype>::backward_cpu_bias(Dtype* bias,
    const Dtype* input) {
  caffe_cpu_gemv<Dtype>(CblasNoTrans, num_output_, height_out_ * width_out_, 1.,
      input, bias_multiplier_.cpu_data(), 1., bias);
}

#ifndef CPU_ONLY

template <typename Dtype>
void BaseConvolutionLayer<Dtype>::forward_gpu_gemm(const Dtype* input,
    const Dtype* weights, Dtype* output, bool skip_im2col) {
  const Dtype* col_buff = input;
  if (!is_1x1_) {
    if (!skip_im2col) {
      conv_im2col_gpu(input, col_buffer_.mutable_gpu_data());
    }
    col_buff = col_buffer_.gpu_data();
  }
  for (int g = 0; g < group_; ++g) {
    caffe_gpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, conv_out_channels_ /
        group_, conv_out_spatial_dim_, kernel_dim_ / group_,
        (Dtype)1., weights + weight_offset_ * g, col_buff + col_offset_ * g,
        (Dtype)0., output + output_offset_ * g);
  }
}

template <typename Dtype>
void BaseConvolutionLayer<Dtype>::forward_gpu_bias(Dtype* output,
    const Dtype* bias) {
  caffe_gpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, num_output_,
      height_out_ * width_out_, 1, (Dtype)1., bias, bias_multiplier_.gpu_data(),
      (Dtype)1., output);
}

template <typename Dtype>
void BaseConvolutionLayer<Dtype>::backward_gpu_gemm(const Dtype* output,
    const Dtype* weights, Dtype* input) {
  Dtype* col_buff = col_buffer_.mutable_gpu_data();
  if (is_1x1_) {
    col_buff = input;
  }
  for (int g = 0; g < group_; ++g) {
    caffe_gpu_gemm<Dtype>(CblasTrans, CblasNoTrans, kernel_dim_ / group_,
        conv_out_spatial_dim_, conv_out_channels_ / group_,
        (Dtype)1., weights + weight_offset_ * g, output + output_offset_ * g,
        (Dtype)0., col_buff + col_offset_ * g);
  }
  if (!is_1x1_) {
    conv_col2im_gpu(col_buff, input);
  }
}

template <typename Dtype>
void BaseConvolutionLayer<Dtype>::weight_gpu_gemm(const Dtype* input,
    const Dtype* output, Dtype* weights) {
  const Dtype* col_buff = input;
  if (!is_1x1_) {
    conv_im2col_gpu(input, col_buffer_.mutable_gpu_data());
    col_buff = col_buffer_.gpu_data();
  }
  for (int g = 0; g < group_; ++g) {
    caffe_gpu_gemm<Dtype>(CblasNoTrans, CblasTrans, conv_out_channels_ / group_,
        kernel_dim_ / group_, conv_out_spatial_dim_,
        (Dtype)1., output + output_offset_ * g, col_buff + col_offset_ * g,
        (Dtype)1., weights + weight_offset_ * g);
  }
}

template <typename Dtype>
void BaseConvolutionLayer<Dtype>::backward_gpu_bias(Dtype* bias,
    const Dtype* input) {
  caffe_gpu_gemv<Dtype>(CblasNoTrans, num_output_, height_out_ * width_out_, 1.,
      input, bias_multiplier_.gpu_data(), 1., bias);
}

#endif  // !CPU_ONLY

INSTANTIATE_CLASS(BaseConvolutionLayer);

}  // namespace caffe