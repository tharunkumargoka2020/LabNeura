#pragma once

#include <torch/torch.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

class SingleHead : public torch::nn::Module {
public:
    SingleHead(int embed_size);
    void forward(const torch::Tensor& x, torch::Tensor& output);

private:
    torch::nn::Linear query{nullptr};
    torch::nn::Linear key{nullptr};
    torch::nn::Linear value{nullptr};
    double scale;
};