#ifndef CAFFE_CODEGEN_H
#define CAFFE_CODEGEN_H

#include <vector>

namespace caffe {


    struct KernelCell {
        int kernelCol;
        int kernelRow;
        float value;

        KernelCell(int _kernelCol, int _kernelRow, float _value)
                : kernelCol(_kernelCol)
                , kernelRow(_kernelRow)
                , value(_value)
        {
        }

        bool operator <(const KernelCell &second) const {
            if (this->kernelCol == second.kernelCol) {
                return this->kernelRow < second.kernelRow;
            } else {
                return this->kernelCol < second.kernelCol;
            }
        }
    };


    template<typename Dtype>
    std::string directConvolutionRegistersCodegen(
            const Dtype *kernel,
            const int *cellInfo,
            const int *indicesChannels, // size = nInputChannels * nOutputChannels

            const int kernelSizeX,

            const int kernelSizeY,

            const int nInputChannels,
            const int nOutputChannels
    ) {
        std::stringstream code;

        code << "void run(const float *input, const int imgSizeX, const int imgSizeY, float *output, const int outputPitchX, const int resSizeX, const int resSizeY) {" << std::endl;

        code << "\tconst int kernelSizeY = " << kernelSizeY << ";" << std::endl;
        code << "\tconst int inputSize = imgSizeX * imgSizeY;" << std::endl;
        for (int outputChannelIdx = 0; outputChannelIdx < nOutputChannels; outputChannelIdx++) {
            code << "\t{" << std::endl;

            code << "\tint outputChannelIdx=" << outputChannelIdx << ";" << std::endl;
            code << "\tfor (int dim = 0; dim < resSizeX / 8; dim++) {" << std::endl;
            code << "\t\tconst int shift = dim << 3;" << std::endl;

            int totalNonZeroElements = 0;

            for (int inputChannelIdx = 0; inputChannelIdx < nInputChannels; inputChannelIdx++) {
                const int beginIdx = indicesChannels[outputChannelIdx * nInputChannels + inputChannelIdx];
                const int endIdx = indicesChannels[outputChannelIdx * nInputChannels + inputChannelIdx + 1];

                totalNonZeroElements += endIdx - beginIdx;
            }

            if (totalNonZeroElements != 0) {
                code << "\t\t__m256 collectedOutput[" << kernelSizeY << "];" << std::endl;
                for (int i = 0; i < kernelSizeY; i++) {
                    code << "\t\tcollectedOutput[" << i << "] = _mm256_setzero_ps();" << std::endl;
                }
            }

            code << "\t\tfor (int inputRow = 0; inputRow < imgSizeY; inputRow++) {" << std::endl;
            if (totalNonZeroElements != 0) {
                for (int i = kernelSizeY - 1; i > 0; i--) {
                    code << "\t\t\tcollectedOutput[" << i << "] = collectedOutput[" << i - 1 << "];" << std::endl;
                }
                code << "\t\t\tcollectedOutput[0] = _mm256_setzero_ps();" << std::endl;

                for (int inputChannelIdx = 0; inputChannelIdx < nInputChannels; inputChannelIdx++) {
                    const int beginIdx = indicesChannels[outputChannelIdx * nInputChannels + inputChannelIdx];
                    const int endIdx = indicesChannels[outputChannelIdx * nInputChannels + inputChannelIdx + 1];

                    if (beginIdx == endIdx) {
                        continue;
                    }

                    std::vector<KernelCell> cells;

                    for (int idx = beginIdx; idx < endIdx; idx++) {
                        const int kernelColRow = cellInfo[idx];
                        const int kernelCol = kernelColRow & 0xFF;
                        const int kernelRow = (kernelColRow >> 8) & 0xFF;
                        const float value = kernel[idx];

                        cells.push_back(KernelCell(kernelCol,kernelRow,value));
                    }

                    // sorted by column is preferred here due to memory access way
                    std::sort(cells.begin(), cells.end());

                    code << "\t{" << std::endl;
                    code << "\t\t\tconst int inputChannelIdx = " << inputChannelIdx << ";" << std::endl;
                    code << "\t\t\tconst int inputOffset = inputSize * inputChannelIdx + inputRow * imgSizeX + shift;"
                         << std::endl;

                    for (int kernelValueIdx = 0; kernelValueIdx < cells.size(); kernelValueIdx++) {
                        const int kernelCol = cells[kernelValueIdx].kernelCol;
                        const int kernelRow = cells[kernelValueIdx].kernelRow;
                        const Dtype value = cells[kernelValueIdx].value;

                        code << "\t\t\t{" << std::endl;
                        code << "\t\t\t\tconst int kernelCol=" << kernelCol << ";" << std::endl;
                        code << "\t\t\t\tconst int kernelRow=" << kernelRow << ";" << std::endl;
                        code << "\t\t\t\tconst float value=" << value << ";" << std::endl;
                        code << "\t\t\t\t__m256 multiplier = _mm256_set1_ps(value);" << std::endl;
                        code << "\t\t\t\t__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);"
                             << std::endl;
                        code
                                << "\t\t\t\tcollectedOutput[kernelRow] = _mm256_add_ps(collectedOutput[kernelRow], _mm256_mul_ps(multiplier, generated));"
                                << std::endl;
                        code << "\t\t\t}" << std::endl;
                    }
                    code << "\t}" << std::endl;
                }
                code << "\t\t\tconst int realRowIdx = inputRow - (kernelSizeY - 1);" << std::endl;
                code << "\t\t\tif (realRowIdx >= 0) {" << std::endl;
                code << "\t\t\t\t_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[kernelSizeY - 1]);" << std::endl;
                code << "\t\t\t}" << std::endl;
            } else {
                code << "\t\t\tconst int realRowIdx = inputRow - (kernelSizeY - 1);" << std::endl;
                code << "\t\t\tif (realRowIdx >= 0) {" << std::endl;
                code << "\t\t\t\t_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());" << std::endl;
                code << "\t\t\t}" << std::endl;
            }

            code << "\t\t}" << std::endl;
            code << "\t}" << std::endl;
            code << "\t}" << std::endl;
        }
        code << "}" << std::endl; // function
        return code.str();
    }


    template<typename Dtype>
    std::string directConvolutionRegistersCodegenUnrolled(
            const Dtype *kernel,
            const int *cellInfo,
            const int *indicesChannels, // size = nInputChannels * nOutputChannels

            const int kernelSizeX,

            const int kernelSizeY,

            const int nInputChannels,
            const int nOutputChannels
    ) {
        std::stringstream code;

        code << "void run(const float *input, const int imgSizeX, const int imgSizeY, float *output, const int outputPitchX, const int resSizeX, const int resSizeY) {" << std::endl;

        code << "\tconst int kernelSizeY = " << kernelSizeY << ";" << std::endl;
        for (int outputChannelIdx = 0; outputChannelIdx < nOutputChannels; outputChannelIdx++) {
            code << "\t{" << std::endl;

            code << "\tint outputChannelIdx=" << outputChannelIdx << ";" << std::endl;
            code << "\tfor (int dim = 0; dim < resSizeX / 8; dim++) {" << std::endl;
            code << "\t\tconst int shift = dim << 3;" << std::endl;
            int totalNonZeroElements = 0;

            for (int inputChannelIdx = 0; inputChannelIdx < nInputChannels; inputChannelIdx++) {
                const int beginIdx = indicesChannels[outputChannelIdx * nInputChannels + inputChannelIdx];
                const int endIdx = indicesChannels[outputChannelIdx * nInputChannels + inputChannelIdx + 1];

                totalNonZeroElements += endIdx - beginIdx;
            }
            if (totalNonZeroElements != 0) {
                code << "\t\t__m256 collectedOutput[" << kernelSizeY << "];" << std::endl;
                for (int i = 0; i < kernelSizeY; i++) {
                    code << "\t\tcollectedOutput[" << i << "] = _mm256_setzero_ps();" << std::endl;
                }
            }

            // unrolling this loop on kernelSizeY
            code << "\t\tfor (int inputRowStart = 0; inputRowStart < imgSizeY; inputRowStart += kernelSizeY) {" << std::endl;
            for (int step = 0; step < kernelSizeY; step++) {
                code << "\t\t{" << std::endl;
                code << "\t\tconst int inputRow = inputRowStart + " << step << ";" << std::endl;
                code << "\t\tif (inputRow == imgSizeY) { break; }" << std::endl;

                const int head = (-step + kernelSizeY) % kernelSizeY;
                if (totalNonZeroElements != 0) {
                    code << "\t\t\tcollectedOutput[" << head << "] = _mm256_setzero_ps();" << std::endl;
                }

                for (int inputChannelIdx = 0; inputChannelIdx < nInputChannels; inputChannelIdx++) {
                    const int beginIdx = indicesChannels[outputChannelIdx * nInputChannels + inputChannelIdx];
                    const int endIdx = indicesChannels[outputChannelIdx * nInputChannels + inputChannelIdx + 1];

                    if (beginIdx == endIdx) {
                        continue;
                    }

                    std::vector<KernelCell> cells;

                    for (int idx = beginIdx; idx < endIdx; idx++) {
                        const int kernelColRow = cellInfo[idx];
                        const int kernelCol = kernelColRow & 0xFF;
                        const int kernelRow = (kernelColRow >> 8) & 0xFF;
                        const float value = kernel[idx];

                        cells.push_back(KernelCell(kernelCol,kernelRow,value));
                    }

                    // sorted by column is preferred here due to memory access way
                    std::sort(cells.begin(), cells.end());

                    code << "\t\t\t\t{" << std::endl;
                    code << "\t\t\t\t\tconst int inputChannelIdx = " << inputChannelIdx << ";" << std::endl;
                    code << "\t\t\t\t\tconst int inputOffset = imgSizeX * (imgSizeY * inputChannelIdx + inputRow) + shift;" << std::endl;

                    for (int kernelValueIdx = 0; kernelValueIdx < cells.size(); kernelValueIdx++) {
                        const int kernelCol = cells[kernelValueIdx].kernelCol;
                        const int kernelRow = cells[kernelValueIdx].kernelRow;
                        const Dtype value = cells[kernelValueIdx].value;

                        code << "\t\t\t{" << std::endl;
                        code << "\t\t\t\tconst int kernelCol=" << kernelCol << ";"<< std::endl;
                        code << "\t\t\t\t//const int kernelRow=" << kernelRow << ";"<< std::endl;
                        code << "\t\t\t\tconst float value=" << value << ";" << std::endl;
                        code << "\t\t\t\t__m256 multiplier = _mm256_set1_ps(value);"<< std::endl;
                        code << "\t\t\t\t__m256 generated = _mm256_loadu_ps(input + inputOffset + kernelCol);"<< std::endl;
                        const int idxToWrite = (head + kernelRow) % kernelSizeY;
                        code << "\t\t\t\tcollectedOutput[" << idxToWrite << "] = _mm256_add_ps(collectedOutput[" << idxToWrite << "], _mm256_mul_ps(multiplier, generated));"<< std::endl;
                        code << "\t\t\t}" << std::endl;
                    }
                    code << "\t\t\t\t}" << std::endl; // inputChannel
                }
                code << "\t\t\tconst int realRowIdx = inputRow - (kernelSizeY - 1);" << std::endl;
                code << "\t\t\tif (realRowIdx >= 0) {" << std::endl;
                if (totalNonZeroElements == 0) {
                    code
                            << "\t\t\t\t_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, _mm256_setzero_ps());"
                            << std::endl;
                } else {
                    code
                            << "\t\t\t\t_mm256_storeu_ps(output + outputChannelIdx * outputPitchX * resSizeY + outputPitchX * realRowIdx + shift, collectedOutput[" << (head - 1 + kernelSizeY) % kernelSizeY << "]);"
                            << std::endl;
                }
                code << "\t\t\t}" << std::endl; // write
                code << "\t\t\t}" << std::endl; // step
            }
            code << "\t\t}" << std::endl;// inputRowStart
            code << "\t\t}" << std::endl; // dim
            code << "\t}" << std::endl; // outputChannel
        }
        code << "}" << std::endl; // function
        return code.str();
    }


    template<typename Dtype>
    std::string directConvolutionSparseOutputReusage(
            const Dtype *kernel,
            const int *cellInfo,
            const int *indicesChannels, // size = nInputChannels * nOutputChannels

            const int kernelSizeX,

            const int kernelSizeY,

            const int nInputChannels,
            const int nOutputChannels
    ) {
        std::stringstream code;

        code << "template<> void runOutputReusage<float>(const float *input, const int imgSizeX, const int imgSizeY, float *output, const int outputPitchX, const int resSizeX, const int resSizeY) {" << std::endl;

        for (int row = 0; row < nOutputChannels; row++) {
            code << "\t{" << std::endl;
            code << "\t\tconst int outputChannelIdx=" << row << ";" << std::endl;

            code << "\t\tconst int res_off = outputPitchX * resSizeY * outputChannelIdx;" << std::endl;


            code << "\t\tfor (int dim = 0; dim < resSizeX / 8; dim++) {" << std::endl;
            code << "\t\t\tconst int shift = dim << 3;" << std::endl;

            code << "\t\t\tfor (int y = 0; y < resSizeY; y++) {" << std::endl;
            code << "\t\t\t\t__m256 out = _mm256_setzero_ps();" << std::endl;


                for (int inputChannelIdx = 0; inputChannelIdx < nInputChannels; inputChannelIdx++) {


                    const int begin = indicesChannels[row * nInputChannels + inputChannelIdx];
                    const int end = indicesChannels[row * nInputChannels + inputChannelIdx + 1];

                    if (begin == end) {
                        continue;
                    }

                    // natural sorting (i.e. by row is preferred here)
                    code << "\t\t\t\t{" << std::endl;
                    code << "\t\t\t\t\tconst int inputChannelIdx = " << inputChannelIdx << ";" << std::endl;
                    code << "\t\t\t\t\tconst int initialOffset = imgSizeX * (imgSizeY * inputChannelIdx + y) + shift;" << std::endl;

                    for (int idx = begin; idx < end; idx++) {
                        const int kernelColRow = cellInfo[idx];
                        const int kernelCol = kernelColRow & 0xFF;
                        const int kernelRow = (kernelColRow >> 8) & 0xFF;
                        const float value = kernel[idx];

                        code << "\t\t\t\t\t{__m256 factor = _mm256_set1_ps(" << value << ");" << std::endl;

                        code << "\t\t\t\t\t\tconst int kernelCol=" << kernelCol << ";"<< std::endl;
                        code << "\t\t\t\t\t\tconst int kernelRow=" << kernelRow << ";"<< std::endl;

                        code << "\t\t\t\t\t\tconst int inOffset = initialOffset + imgSizeX * kernelRow + kernelCol;" << std::endl;

                        code << "\t\t\t\t\t\t__m256 in = _mm256_loadu_ps(input + inOffset);" << std::endl;
                        code << "\t\t\t\t\t\t__m256 multiplied = _mm256_mul_ps(in, factor);" << std::endl;
                        code << "\t\t\t\t\t\tout = _mm256_add_ps(multiplied, out);}" << std::endl;
                    }
                    code << "\t\t\t\t}" << std::endl; // inputChannelIdx
                }

            code << "\t\t\t\t_mm256_storeu_ps(output + res_off + shift + y * outputPitchX, out);" << std::endl;
            code << "\t\t\t}" << std::endl;
            code << "\t\t}" << std::endl;
            code << "\t}" << std::endl;
        }
        code << "}" << std::endl; // function
        return code.str();
    }


}
#endif //CAFFE_CODEGEN_H
