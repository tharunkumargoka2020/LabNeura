#include <iostream>
#include <cmath>
#include "ml/gpt2.h"

SingleHead::SingleHead(int embed_size) 
    : query(torch::nn::Linear(embed_size, embed_size)),
        key(torch::nn::Linear(embed_size, embed_size)),
        value(torch::nn::Linear(embed_size, embed_size)),
        scale(sqrt(embed_size)) {
    
    // Register the layers as submodules
    register_module("query", query);
    register_module("key", key);
    register_module("value", value);
        
}

void SingleHead::forward(const torch::Tensor& x, torch::Tensor& output) {
    // Compute query, key, and value matrices
    auto Q = query->forward(x);
    auto K = key->forward(x);
    auto V = value->forward(x);

    // Compute attention scores (QK^T) / sqrt(embed_size)
    auto scores = torch::matmul(Q, K.transpose(-2, -1)) / scale;

    // Apply softmax to get attention weights
    auto attention_weights = torch::softmax(scores, -1);

    // Compute the output by multiplying attention weights with value
    output = torch::matmul(attention_weights, V);
}