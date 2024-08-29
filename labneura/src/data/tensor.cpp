#include "data/tensor.h"

// Constructor from std::vector<float>
CustomTensor::CustomTensor(const std::vector<float>& data) 
    : tensor_(convertToTensor(data).to(getBestDevice())) {}

// Constructor from std::vector<int>
CustomTensor::CustomTensor(const std::vector<int>& data)
    : tensor_(convertToTensor(data).to(getBestDevice())) {}

// Constructor from at::Tensor
CustomTensor::CustomTensor(const at::Tensor& tensor)
    : tensor_(tensor.to(getBestDevice())) {}

// Constructor from numpy array
CustomTensor::CustomTensor(const pybind11::array& numpy_array)
    : tensor_(convertToTensor(numpy_array).to(getBestDevice())) {}

// Get the underlying tensor
at::Tensor CustomTensor::getTensor() const {
    return tensor_;
}

// Determine the best device
at::Device CustomTensor::getBestDevice() const {
    if (torch::cuda::is_available()) {
        return at::Device(at::kCUDA);
    } else if (torch::hasHIP()) {
        return at::Device(at::kHIP);
    } else {
        return at::Device(at::kCPU);
    }
}

// Convert std::vector<float> to at::Tensor
at::Tensor CustomTensor::convertToTensor(const std::vector<float>& data) const {
    return torch::tensor(data);
}

// Convert std::vector<int> to at::Tensor
at::Tensor CustomTensor::convertToTensor(const std::vector<int>& data) const {
    return torch::tensor(data);
}

// Convert numpy array to at::Tensor
at::Tensor CustomTensor::convertToTensor(const pybind11::array& numpy_array) const {
    // Request buffer information from the numpy array
    pybind11::buffer_info buf_info = numpy_array.request();

    // Check if the data type is float (assuming that's the tensor type you want)
    if (buf_info.format != pybind11::format_descriptor<float>::format()) {
        throw std::runtime_error("Expected numpy array of type float.");
    }

    // Convert shape to vector<int64_t> for PyTorch tensor creation
    std::vector<int64_t> shape(buf_info.shape.size());
    std::transform(buf_info.shape.begin(), buf_info.shape.end(), shape.begin(),
                   [](const std::size_t dim) { return static_cast<int64_t>(dim); });

    // Create the tensor using the data pointer from the numpy array
    return torch::from_blob(static_cast<float*>(buf_info.ptr), shape, torch::kFloat).clone();
}