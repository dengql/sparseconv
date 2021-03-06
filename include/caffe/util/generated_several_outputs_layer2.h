#ifndef CAFFE_CODEGEN_LAYER2_UNFOLDED_H
#define CAFFE_CODEGEN_LAYER2_UNFOLDED_H

template<typename Dtype>
void run50SeveralOutputs(const Dtype *img, const int imgSizeX, const int imgSizeY, Dtype *output, const int outputPitchX,
const int outputSizeX, const int outputSizeY);

template<>
void run50SeveralOutputs<double>(const double *img, const int imgSizeX, const int imgSizeY, double *output, const int outputPitchX,
const int outputSizeX, const int outputSizeY) {
throw 1;
}

template<>
void run50SeveralOutputs(const float *input, const int imgSizeX, const int imgSizeY, float *output, const int outputPitchX, const int resSizeX, const int resSizeY) {
	const int kernelSizeY = 5;
	const int inputSize = imgSizeX * imgSizeY;
	{
	int outputChannelIdx=0;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0962267;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0844744;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.115854;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.087093;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.117631;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0901724;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.0971134;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0800291;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.140035;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.107228;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.194571;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.090619;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.0949185;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.149;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.227651;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.195615;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.137566;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.109253;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0743691;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.0880255;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.121079;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.085332;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.0723767;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.0734622;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0724659;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.0856205;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.0998973;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0965637;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.105076;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.180652;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=0.0873525;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.119319;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.0939081;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.224018;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0797489;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.0800868;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0861403;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.133764;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.126302;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.0976002;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.0766736;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.162675;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.152247;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0672784;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.113335;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 18;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0758972;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.100397;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.0778442;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=0.155049;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.119183;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.0977676;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.2134;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.226526;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.334498;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0898559;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=1;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.075621;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0832304;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.10521;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.0880511;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.0800956;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.131415;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.105543;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.0888557;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.168989;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.105145;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.14716;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.120462;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.06649;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.105592;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0892466;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.0850468;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.100154;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.0835156;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.112351;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=0.114672;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.0759203;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.139077;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.160606;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.0891006;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.119015;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.102302;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.0896665;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.095138;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.115657;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.103061;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.113316;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.139031;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.135486;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.159014;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0907559;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.168421;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.106634;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.219572;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.158671;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.159915;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.119445;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.262878;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.30445;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.0834563;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.174998;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.202558;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.193542;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.0888196;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 17;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.0865489;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.0935718;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.137286;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.0837638;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.126899;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.125693;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0748015;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.164978;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.0894365;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.153743;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0665279;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.0921936;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=2;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0847939;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.0892034;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0890025;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.239175;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.0959884;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.109093;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.0813905;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0942986;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.119172;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.1235;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.0951169;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.114087;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.150053;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.104137;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.110909;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.0880755;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.103587;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0870259;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.0761365;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.10429;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0789495;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.0994556;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.100761;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.101587;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.175375;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=0.0863141;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.0943601;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.154629;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.139261;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.111048;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.150504;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0920056;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.132459;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.130881;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.191673;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.097653;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.133395;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.130166;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.0745018;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.127104;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.0889678;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.11028;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=0.104548;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.155534;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.0874695;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.101713;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.175916;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.119287;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.127526;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.0996356;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0999871;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.160347;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.141814;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.0979483;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=3;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.0779188;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.0772077;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.106685;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0870592;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.0787443;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0825109;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.0990487;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.079468;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.0988611;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0753826;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.127521;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.150629;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.180087;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.119387;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0725039;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.0866931;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=4;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.103327;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.086106;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.100583;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0850608;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.144678;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0682415;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=0.123399;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=0.148626;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.140381;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.136723;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.111977;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=0.123662;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.165432;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.220888;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.0948303;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=0.125272;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.16906;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0937091;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.0887833;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.0925404;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.131552;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.139237;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0772846;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.121342;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.106773;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.0926005;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.091755;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.0867957;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0953289;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.0811346;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.105253;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.108158;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.115899;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.0843575;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.0821086;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.0832002;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.125342;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.094491;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.169812;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.100172;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.0840623;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0867825;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.14739;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.136565;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.297372;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.159823;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.088395;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.0905967;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.122748;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0877351;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.167866;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.0979196;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.105756;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=5;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.117745;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.133699;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.117471;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.0965142;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.0870465;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.116553;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.0906439;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.106967;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0881769;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.16088;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0960158;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0930259;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.0997052;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.0784685;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.094165;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0754893;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.0653143;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.131305;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0875551;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.0916231;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.095016;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.174865;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.0789238;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0860155;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.243027;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.166578;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.119188;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.0989096;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0910387;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.134981;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=6;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.0867528;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.0860998;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.0948687;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.0985397;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.098704;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.116725;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0999331;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.109835;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.135009;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.21514;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.0636052;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.077166;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.0898488;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.145617;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.14137;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.127117;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.185791;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.119352;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.0914925;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.245386;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0842055;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.107178;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.0815265;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.0850104;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0847846;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.0853564;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.0748462;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.10326;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.110886;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0967489;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.0787723;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.0729055;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.126012;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.139389;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.105555;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=0.186543;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=0.0932505;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.0866825;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.162477;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.234431;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.0801109;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.216026;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.178317;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.0804904;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.173971;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0678279;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.100046;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.0966374;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.139703;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.0956385;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.0805137;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.105149;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.130451;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.111173;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0861174;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.143814;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=7;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.0920848;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0825418;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.0802229;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.0943389;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.100683;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0956136;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.0838708;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.123454;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.0871141;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.104759;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.106475;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.152359;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.112294;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.110222;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.130408;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.180812;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.0809228;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.110876;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.110809;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0693809;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.112372;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0923056;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.112757;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.114518;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=0.0895692;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=0.169902;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.115819;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.111188;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.262153;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.127959;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.135302;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.277003;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.131161;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.219125;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.0766062;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0996636;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.0935541;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.113645;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.137016;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.132127;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.103474;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 11;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.0740664;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.10141;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.0822431;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.135113;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.128936;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.129994;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.124371;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.147261;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.138334;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0739948;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.113474;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.0997861;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.140756;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0971029;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.190819;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.160717;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0726729;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.248424;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.105159;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.094151;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.134539;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.156299;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.130356;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.113988;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.170236;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0681606;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.104257;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=8;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.113563;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.113702;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.0997539;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.126434;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.10695;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0989068;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.0901937;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.0799678;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.0977948;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.172167;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.111954;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0910278;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.141301;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.109889;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.0919135;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.101655;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.176716;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.139729;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0763849;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=0.138587;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.0709881;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.18001;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.356874;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.097998;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.35993;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.105553;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.0827305;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.310296;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.151349;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.075141;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.0912165;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.125361;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.145669;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.138202;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=0.078899;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 11;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.0807292;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.141682;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.0956773;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.191376;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.0666355;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.145545;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.210964;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.0938235;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.088447;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.129207;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.129603;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=0.121043;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.10579;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.158313;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.111998;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.140741;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.170085;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.0892906;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.118997;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.124695;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.153882;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.150448;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.105802;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 17;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.0762789;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 18;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.0777527;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.113815;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0820231;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0773116;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.0851332;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.213762;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.121194;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.0940043;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.19968;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.182399;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.11945;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.17942;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.0943094;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.236079;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.137524;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.13409;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=9;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.110519;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.0712501;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.0924206;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.0870904;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.0830293;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.0765312;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=0.129786;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.125159;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.0753979;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=0.114103;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.129067;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.110745;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.110532;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=10;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0772874;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.0928444;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.0782257;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.130365;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.0835263;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.11012;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.0879567;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0891315;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.0849913;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0830908;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.136614;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.13358;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.128414;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.1997;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.0847588;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.123001;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.0565811;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.125392;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.108806;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0807893;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.0759018;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.0892281;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=0.0974511;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.125855;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.123137;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.109825;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.121914;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.168447;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.116184;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.11509;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.0810037;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.0773545;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.095385;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0945198;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.0858599;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.140686;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.0809517;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.074463;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.0928387;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.136689;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.112164;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.133124;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.1002;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.0819091;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.110076;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.11353;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0871974;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.0881525;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.117487;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.114762;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.143201;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.0775762;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0981107;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.11998;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.135616;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.105851;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.104469;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.139772;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.0920218;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.101842;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.107109;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.135564;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.158933;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.135685;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 18;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.0840334;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.10156;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.0872514;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.188892;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.168423;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.0934455;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.0716224;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.0937879;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.200959;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.107963;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=11;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.0850881;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0977313;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.134867;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.0992802;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.0838312;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.0798863;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.11975;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0820744;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.124808;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.122897;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=0.11396;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.100772;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.0849589;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.0987558;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.20054;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.0766985;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.108648;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.106631;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.140743;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.0922559;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.102575;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.118539;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.12278;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.123597;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.0838313;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.0956809;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.104733;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.131783;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.0817756;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.106888;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.152653;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.0870479;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.100517;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.07253;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.132198;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.074072;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0973514;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.154984;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.133337;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.18528;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.13472;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=0.109205;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.123638;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=12;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.0942564;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0887085;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 6;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.0775959;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.0852994;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.0844413;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.111432;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.125117;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.0860642;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0981082;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.100565;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.098937;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.117538;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.169396;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=0.0889671;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.0783278;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.125797;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.087846;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=0.0944143;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.119037;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.202944;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.21011;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.0853357;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0980844;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.172418;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=13;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0943317;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.0859894;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.114086;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.0941739;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0693603;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.114575;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.0919943;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.0906981;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0738837;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.126646;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=0.0958105;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.0809737;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.129521;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.140427;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.257652;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.171159;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.246413;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=0.0858276;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.087448;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.0883508;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.109078;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.148357;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.087771;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.0937541;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.111863;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.114657;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.139206;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.22216;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0982258;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0813903;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.0895943;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.121787;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.0781304;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.128777;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.187479;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.1398;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.0901454;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.103022;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.177266;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.116475;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.14254;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.0900394;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0858841;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 18;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.0867624;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.111876;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.110633;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.140135;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.160348;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.122437;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.105299;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.0899813;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.242824;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=14;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
			}
		}
	}
	}
	{
	int outputChannelIdx=15;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.0859981;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.0838375;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.11394;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0839137;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.080552;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.125912;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.0897398;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.106934;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.0792969;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=0.0879883;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.172305;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.0841658;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.0814871;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.232536;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.108624;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.0967917;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0878036;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0700198;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.0991426;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.115818;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.0809259;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.217336;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.0678035;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.124877;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.194671;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.102272;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.169687;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.205593;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.136562;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0830561;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0999905;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.0988056;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.126874;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.152604;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.160292;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0849051;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.091227;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.0935476;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.10869;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.100108;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.0781687;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.175286;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.104999;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.283413;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.215725;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.15741;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.121944;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.104927;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0783575;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0870812;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 18;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.0764424;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.10872;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.0892419;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=0.174202;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.140138;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.14361;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.14808;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.142906;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.208097;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.0807371;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.119492;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.169279;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=16;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
			}
		}
	}
	}
	{
	int outputChannelIdx=17;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.0841785;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0856641;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.109319;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.0774846;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0845919;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0732171;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.0853525;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.115373;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.108841;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.0764752;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.0837843;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.10275;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.119411;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.0858369;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.165222;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.117871;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=18;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.0911551;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.0704895;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.134789;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.0851036;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=19;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
			}
		}
	}
	}
	{
	int outputChannelIdx=20;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0734521;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=0.0811747;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0854197;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.0808819;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.0715709;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=0.083013;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.1047;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.179409;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.096428;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.211004;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.0876085;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=0.0865669;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.0867808;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.0738434;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.077949;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.0978356;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.090928;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.092319;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.0897179;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0723755;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.10623;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.096104;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.0882244;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.0873597;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.139619;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0766427;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.156365;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.143804;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.0947915;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.0952379;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.109929;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0812292;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.109745;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0890759;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=21;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.0872684;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.0917594;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.0801733;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.0984575;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.11166;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.0946015;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.148302;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.0937416;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.0904121;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.122954;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.0829394;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.100708;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.095072;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.116981;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.0977974;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.106448;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.102005;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.0954797;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.0916075;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.0837641;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.10531;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.0906965;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.0941381;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.0883965;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.116709;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=22;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0916827;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0932864;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0946767;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.11964;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.105252;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0912862;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0850904;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0912518;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0971618;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.102954;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=0.147891;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.0792791;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.178421;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.183237;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0895101;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.118944;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.159092;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.195142;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.232441;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0813143;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.112747;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.0851863;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.114362;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=0.0705777;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.11077;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.0952768;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.112314;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.148623;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0823222;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0946903;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0745257;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.104027;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.113124;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.0849613;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.113942;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.163378;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.102572;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.126676;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.0856795;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.102225;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.133703;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.212885;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.231971;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.226046;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.114754;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0854446;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.106838;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.0845336;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.0801922;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.0896244;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.10619;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.231092;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.21521;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.134522;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.189727;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.0989978;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.108821;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.0888544;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.215915;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.12403;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.0772091;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 18;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.105518;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.192076;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.100948;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.120644;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.125792;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.0794171;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0917484;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0685671;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.0747423;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=23;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.0946372;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.0955228;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.127464;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.0776987;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.111044;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.158058;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0996163;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.137975;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.0978467;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 4;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.072695;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.097015;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.121581;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.149103;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.0925671;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.206644;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.145559;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.126647;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.127524;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.0799789;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0921712;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.123457;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0979208;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.179445;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.14458;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.153357;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.115316;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.0920427;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.138573;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.127303;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.256155;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.107814;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.325046;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.212707;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=0.266819;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.187344;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.215664;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.131279;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.11118;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.0968534;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.13415;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.141818;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.145529;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.140268;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.0786333;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.11274;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0866571;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.069856;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.11973;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.107011;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0647216;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.12993;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=0.126535;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.0986921;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.115947;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.166188;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.220566;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.183608;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.125648;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.17983;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.252232;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.169633;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 18;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.0856632;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.0950887;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=0.119715;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.124071;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.147784;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.148486;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.164963;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.0946155;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.107027;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.0989683;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.0902519;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.150302;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0778631;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.135472;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.139187;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.0768112;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=24;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
			}
		}
	}
	}
	{
	int outputChannelIdx=25;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
			}
		}
	}
	}
	{
	int outputChannelIdx=26;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.080336;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0955836;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.103614;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0782405;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.11198;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.11009;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.148464;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.14185;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.223571;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.216515;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.204545;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.169641;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.1028;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.103261;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.174419;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.0939916;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.102726;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.100867;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.0939716;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.07685;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.125599;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.102547;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0812376;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.135557;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.09935;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.0847388;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0771583;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.132453;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.0946927;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.0967645;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.0913018;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.181828;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.150765;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.167901;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.150504;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.161993;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.133053;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.0831232;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0812854;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.125412;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.119785;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.0919132;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.0701463;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.134725;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.069346;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0821804;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0960264;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=27;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
			}
		}
	}
	}
	{
	int outputChannelIdx=28;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
			}
		}
	}
	}
	{
	int outputChannelIdx=29;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.101878;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.09717;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.0968331;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.0706842;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.0758442;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.132328;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0769701;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0936032;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.0780516;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.0913823;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.0798834;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.0999568;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.080145;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.107401;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.122581;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.0964631;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.148562;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.119391;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=0.105378;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.133549;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.106692;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.0775744;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.103557;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.116696;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.132417;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.0896176;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.0863773;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0820649;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.0913502;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.114447;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.094416;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.100818;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.125285;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.13155;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.119537;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.106261;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.145875;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.088575;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=30;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.0828872;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=31;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.0916723;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.0834551;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0914921;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.0793583;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.0750437;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0766358;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.079074;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.12678;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.0869813;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.101804;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.0856216;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.0920879;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.150606;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0766829;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.131843;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.0693259;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.143418;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.128629;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.12752;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.129786;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.186986;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.077885;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.312188;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.185714;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.0990139;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.182496;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.128273;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.128401;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.166121;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0914367;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.108649;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.127797;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0911706;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.088069;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.0886899;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.0848819;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.145548;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.137434;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.0850504;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.121592;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=0.109623;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.0905932;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.148137;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.163848;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.167518;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.114815;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0891263;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.0873947;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.088284;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.214219;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.118974;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.139294;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.164787;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.194377;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.116785;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0852974;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=32;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.0820794;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.0889692;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0871057;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.1186;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.0929606;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.0773035;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.101103;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.105548;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.101109;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.100785;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.07012;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.136863;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.088928;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=0.0731273;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=33;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.101052;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.0943252;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.0942927;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.0842644;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.0824009;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0991386;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0864374;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.154735;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.0921335;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.0908046;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.133276;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.0845179;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.097201;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0974601;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.160762;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.161394;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.113778;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.168401;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.134754;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=0.104392;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.0961268;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.0862001;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.14757;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.158928;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.122765;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.105877;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.22396;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.156901;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.1298;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.131235;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.082377;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.0816141;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.144114;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0914276;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=0.110744;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0998793;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=0.0718741;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.11142;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.0974718;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0774605;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.135328;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.107155;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.185869;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.0948154;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.0595804;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.132627;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.123529;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.153454;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 18;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0808253;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.105036;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.12481;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.0866249;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.137602;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.0937416;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0985612;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.216158;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.15085;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0851867;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=34;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
			}
		}
	}
	}
	{
	int outputChannelIdx=35;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.0840728;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.0847088;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.0963021;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.0881292;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.0759686;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=36;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.119992;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.125824;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.0689726;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.0838233;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.0723302;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.1899;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0905979;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.087085;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.198958;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.134495;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.162512;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.152182;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.128902;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.201271;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0744225;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.0824013;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.0937719;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.177719;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.106427;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.109383;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.0849666;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.0787971;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.119987;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=0.138205;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.119421;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0984712;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.0838668;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.0972653;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.148566;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.185069;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.0816305;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.143179;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.0803857;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.178726;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.364391;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.111025;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 17;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.0878425;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.0999972;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 18;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.0820483;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.0870558;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.194389;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.232866;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.135091;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.100917;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0951144;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.224606;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=0.0997451;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.100728;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.102942;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=37;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.0810473;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.106395;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0802014;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.0802614;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.0839845;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.104216;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.0841906;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0689672;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.0950813;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.0923448;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0781113;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.122298;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0728623;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0698443;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.155709;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=38;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0911998;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.0803782;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0921548;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.108047;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.09634;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0823479;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.110217;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.152167;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.0957791;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.11757;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.127103;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0813925;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.128453;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0880633;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.0971821;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.107625;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.130118;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.130404;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.0867444;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.10467;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.164056;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.142446;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.156732;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.0896564;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.17716;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.149346;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.080405;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.108451;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.135038;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=0.227619;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.199906;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.09196;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.140017;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.11594;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0929791;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.14131;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.116282;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.110184;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0811998;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.114084;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.130324;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.0903313;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.103481;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.125767;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.0754732;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.0881564;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.112659;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.100974;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=0.0761482;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.17787;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.131787;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.0833798;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.153464;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0922177;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.102301;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0964281;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0973812;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.24499;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.204697;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.149621;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.174959;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.216951;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.124351;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.139155;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.157951;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.134758;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.14353;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0797211;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 18;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.0791336;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.152884;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.0793592;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.167252;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.112688;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.18962;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.105442;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.0926623;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.0816357;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.210826;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0685144;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.102618;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.150986;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.195243;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=39;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0876805;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.154174;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.110116;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.136571;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.129899;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.0954491;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.0960169;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.161577;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.07892;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.0855218;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.162036;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.14224;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.0718048;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.174856;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.134894;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.0839849;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.132942;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.116671;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0809817;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0727548;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0850042;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.0936765;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.209253;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.147299;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.0743332;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.132949;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.123686;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.121554;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.145576;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.102965;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.12666;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.167353;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=0.0786823;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.17669;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.119515;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=0.0758198;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.0813446;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.126052;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.102943;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.0837196;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.0785878;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.105216;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.0761812;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.0840104;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0837249;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.0954928;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.0897873;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.129326;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.129745;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0840546;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0953047;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0758425;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.151733;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.125146;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=0.0860016;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.16321;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.17206;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.108676;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.218538;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.12655;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.213143;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.0842481;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.0939155;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.10742;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.128308;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0811996;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0948069;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 18;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.113483;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.0749723;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.204744;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.145047;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.253469;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.193197;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.153564;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.142653;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0802262;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0759;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=40;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.0839403;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.0778401;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.11665;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.0790568;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.136975;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.101382;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.0880177;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.0881674;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.165463;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0971091;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.0610339;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0920239;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.11712;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.0877703;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.131216;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.119127;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.104;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.158325;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.158715;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.118502;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.132478;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0824302;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0998634;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.111182;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.0896544;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.121608;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.169049;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.111402;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.11506;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.162904;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.151636;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.085493;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 18;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.0807656;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0811087;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.204373;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.0856028;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.149424;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.304863;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.191198;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.162907;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.317362;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.138342;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.13779;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.197257;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.0935271;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=41;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.0735456;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.0748044;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.0791771;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.0968426;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.154013;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.106614;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.123086;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0840645;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.141512;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.167541;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.11166;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.100646;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.130238;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.127394;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.125784;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.120686;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.0799964;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.0788354;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.098034;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.154627;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0980411;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0772855;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=0.0780802;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.104081;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.0921855;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.132097;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0863118;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.14126;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.121532;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.12232;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.0813395;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.0893105;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.0976462;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.108035;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.0869501;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.133835;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.113029;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.121081;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0906751;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.101675;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0913248;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.107194;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.130675;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.224909;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0916223;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.0922474;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.133799;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.160771;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.149841;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.158294;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=0.0960442;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.260016;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.222479;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.124866;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.221479;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.17945;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.104659;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0767457;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.149342;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.123574;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.226592;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.229722;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.091684;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.18334;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0865142;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.131513;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0955816;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.115112;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.0977287;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.0935496;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.0916137;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.107953;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0988602;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.0785096;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.120793;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0956286;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.138622;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.112542;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.111532;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=42;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0826938;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.107853;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.0768708;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.0881949;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=0.0780097;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0763575;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0868555;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.0948735;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.0827098;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=43;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.0820729;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.0770632;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0857745;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.111522;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.105569;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=-0.0855521;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.115708;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.117725;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.0863128;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.12642;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.084944;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.12708;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.116504;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.109648;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0998908;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.11439;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.10068;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.252053;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.0860054;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.149036;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.274384;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.100309;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.168059;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.0876583;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0931946;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.111663;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.112895;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.127713;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.076568;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 11;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.081591;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.11001;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.0891685;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.135641;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.123419;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.111491;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.0831282;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.15918;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.137525;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.126709;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=-0.109814;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.09946;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.082266;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.0915182;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.0854833;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=0.0963669;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 18;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.0840698;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.095555;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.101222;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.102054;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0954115;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.184479;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.114796;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=0.12668;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.0922917;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=0.088244;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=44;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
			}
		}
	}
	}
	{
	int outputChannelIdx=45;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.092892;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0824089;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.140267;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.0915768;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.0908759;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.0980969;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.112424;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.0928819;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.092103;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.114549;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.108185;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.150353;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.133866;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.249702;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.10763;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.175352;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.172995;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.131947;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.110899;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.0867421;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.166557;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.124481;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.0968771;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0737255;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.168574;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=0.108152;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.113208;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.239218;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.115174;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.201296;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.141876;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.178553;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.232037;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.16706;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.184247;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.104381;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.097841;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0912727;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.204972;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.183894;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=1;
				const float value=0.0722855;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.101321;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.0997931;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.0794506;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.106428;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=1;
				const float value=0.0808371;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.133253;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.117839;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.087024;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.0850733;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.084827;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.14243;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.124214;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.072993;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.141211;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.0984445;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.103708;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.237191;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.119706;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.209832;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0919312;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=0.0829338;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.213392;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=4;
				const float value=-0.0812743;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.0923368;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.135221;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.133933;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.159516;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.109259;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.157889;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.087415;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.079584;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=0.101732;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.0908776;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=0.0945728;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.0817193;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.0902116;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.110768;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.0875522;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.116944;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.130481;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0940479;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.186501;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.0713124;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=-0.0768607;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=46;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.0898676;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=-0.100457;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=0.0805529;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=47;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.0752398;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.0782208;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
	{
	int outputChannelIdx=48;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());
			}
		}
	}
	}
	{
	int outputChannelIdx=49;
	for (int dim = 0; dim < resSizeX / 8; dim++) {
		const int shift = dim << 3;
		__m256 collectedOutput[5];
		collectedOutput[0] = _mm256_setzero_ps();
		collectedOutput[1] = _mm256_setzero_ps();
		collectedOutput[2] = _mm256_setzero_ps();
		collectedOutput[3] = _mm256_setzero_ps();
		collectedOutput[4] = _mm256_setzero_ps();
		for (int inputRow = 0; inputRow < imgSizeY; inputRow++) {
			collectedOutput[4] = collectedOutput[3];
			collectedOutput[3] = collectedOutput[2];
			collectedOutput[2] = collectedOutput[1];
			collectedOutput[1] = collectedOutput[0];
			collectedOutput[0] = _mm256_setzero_ps();
	{
			const int inputChannelIdx = 1;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0816678;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0849964;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 2;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.0775923;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.0697536;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.0959272;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.106822;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0792151;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=-0.13;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 7;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.137336;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=-0.117518;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.139941;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=-0.155092;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.145866;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.100433;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.1055;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.0729069;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 9;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=0.10754;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=3;
				const float value=0.0994088;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=3;
				const float value=0.234804;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=-0.114087;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.261913;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=-0.124775;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=0.123127;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=0.106146;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 10;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=0.091286;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=4;
				const float value=-0.118337;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.108537;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0973859;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=-0.0958504;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.122352;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 14;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=-0.0918572;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.106086;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.106594;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=0.108877;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=1;
				const float value=0.123434;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.155934;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0824559;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=0.105071;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.0851788;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 16;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=0;
				const int kernelRow=0;
				const float value=0.111551;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=0;
				const int kernelRow=2;
				const float value=-0.185826;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=0;
				const float value=-0.123268;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=1;
				const int kernelRow=2;
				const float value=-0.0997821;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=-0.111102;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=1;
				const float value=0.099889;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.146488;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=4;
				const float value=-0.0874721;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=0;
				const float value=-0.128672;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.346038;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=0.179292;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.238863;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.0962704;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.192832;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=2;
				const float value=0.0912396;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=3;
				const float value=0.211999;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 17;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=2;
				const float value=0.0719837;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 18;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=0.0827547;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
	{
			const int inputChannelIdx = 19;
			const int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;
			{
				const int kernelCol=2;
				const int kernelRow=0;
				const float value=0.185562;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=2;
				const int kernelRow=3;
				const float value=-0.133227;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=2;
				const float value=0.119658;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=3;
				const float value=-0.121068;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=3;
				const int kernelRow=4;
				const float value=-0.0792873;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=0;
				const float value=-0.110692;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=1;
				const float value=-0.133632;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
			{
				const int kernelCol=4;
				const int kernelRow=4;
				const float value=-0.139038;
				__m256 multiplier = _mm256_set1_ps(value);
				__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);
				collectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));
			}
	}
			const int realRowIdx = inputRow - (kernelSizeY - 1);
			if (realRowIdx >= 0) {
				_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);
			}
		}
	}
	}
}


#endif //CAFFE_CODEGEN_LAYER2_UNFOLDED_H
