#ifndef TENSOR_H
#define TENSOR_H

#include <vector>
#include <iostream>
#include <stdexcept>

#ifdef __ARM_NEON
    #include <arm_neon.h> // For NEON intrinsics
#endif

#ifdef _OPENMP
    #include <omp.h>
#endif

template<typename T>
class Tensor {
public:
    Tensor() = default;

    Tensor(int rows, int cols)
        : rows_(rows), cols_(cols), data_(rows * cols) {}

    Tensor(const std::vector<std::vector<T>>& values) {
        rows_ = values.size();
        cols_ = values[0].size();
        data_.resize(rows_ * cols_);
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                data_[i * cols_ + j] = values[i][j];
            }
        }
    }

    Tensor operator+(const Tensor& other) const {
        if (rows_ != other.rows_ || cols_ != other.cols_) {
            throw std::invalid_argument("Tensor dimensions must match for addition.");
        }

        Tensor result(rows_, cols_);

        #pragma omp parallel for
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; j += 4) {
                #ifdef __ARM_NEON
                std::cout << "Using ARM NEON..!" << std::endl;
                float32x4_t a = vld1q_f32(&data_[i * cols_ + j]);
                float32x4_t b = vld1q_f32(&other.data_[i * cols_ + j]);
                float32x4_t c = vaddq_f32(a, b);
                vst1q_f32(&result.data_[i * cols_ + j], c);
                #else
                result.data_[i * cols_ + j] = data_[i * cols_ + j] + other.data_[i * cols_ + j];
                result.data_[i * cols_ + j + 1] = data_[i * cols_ + j + 1] + other.data_[i * cols_ + j + 1];
                result.data_[i * cols_ + j + 2] = data_[i * cols_ + j + 2] + other.data_[i * cols_ + j + 2];
                result.data_[i * cols_ + j + 3] = data_[i * cols_ + j + 3] + other.data_[i * cols_ + j + 3];
                #endif
            }
        }

        return result;
    }

    Tensor dot(const Tensor& other) const {
        if (cols_ != other.rows_) {
            throw std::invalid_argument("Tensor dimensions must match for dot product.");
        }

        Tensor result(rows_, other.cols_);

        #pragma omp parallel for
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < other.cols_; ++j) {
                float sum = 0;
                int k = 0;
                for (; k <= cols_ - 4; k += 4) {
                    #ifdef __ARM_NEON
                    std::cout << "Using ARM NEON..!" << std::endl;
                    float32x4_t a = vld1q_f32(&data_[i * cols_ + k]);
                    float32x4_t b = vld1q_f32(&other.data_[k * other.cols_ + j]);
                    float32x4_t c = vmulq_f32(a, b);
                    sum += vaddvq_f32(c);
                    #else
                    sum += data_[i * cols_ + k] * other.data_[k * other.cols_ + j];
                    sum += data_[i * cols_ + k + 1] * other.data_[k * other.cols_ + j];
                    sum += data_[i * cols_ + k + 2] * other.data_[k * other.cols_ + j];
                    sum += data_[i * cols_ + k + 3] * other.data_[k * other.cols_ + j];
                    #endif
                }
                // Handle remaining elements
                for (; k < cols_; ++k) {
                    sum += data_[i * cols_ + k] * other.data_[k * other.cols_ + j];
                }
                result.data_[i * other.cols_ + j] = sum;
            }
        }

        return result;
    }

    void print() const {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                std::cout << data_[i * cols_ + j] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    int rows_ = 0;
    int cols_ = 0;
    std::vector<T> data_;
};

#endif // TENSOR_H
