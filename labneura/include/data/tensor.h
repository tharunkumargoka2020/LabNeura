#pragma once

#include <torch/torch.h>
#include <pybind11/numpy.h>

class CustomTensor {
public:
    // Constructors to handle different input types
    CustomTensor(const std::vector<float>& data);
    CustomTensor(const std::vector<int>& data);
    CustomTensor(const at::Tensor& tensor);
    CustomTensor(const pybind11::array& numpy_array);

    // Get the underlying tensor
    at::Tensor getTensor() const;

private:
    // Device-aware tensor storage
    at::Tensor tensor_;

    // Helper method to determine the best device (CUDA, HIP, or CPU)
    at::Device getBestDevice() const;

    // Helper method to convert different inputs to torch::Tensor
    at::Tensor convertToTensor(const std::vector<float>& data) const;
    at::Tensor convertToTensor(const std::vector<int>& data) const;
    at::Tensor convertToTensor(const pybind11::array& numpy_array) const;
};