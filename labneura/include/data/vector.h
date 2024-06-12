#pragma once

#include <vector>
#include <pybind11/pybind11.h>

namespace py = pybind11;

template<typename T>
class VectorWrapper {
public:
    VectorWrapper() = default;

    void push_back(const T &val) {
        if (!vec_.empty() && std::is_same<decltype(val),decltype(vec_.front())>::value)
            throw std::invalid_argument("Inserted value must be of the same type as the first element");
        vec_.push_back(val);
    }

    bool empty() {
        return vec_.size() == 0;
    } 

    void insert(size_t index, const T &val) {
        if (index > vec_.size())
            throw py::index_error();
        if (!vec_.empty() && std::is_same<decltype(val),decltype(vec_.front())>::value)
            throw std::invalid_argument("Inserted value must be of the same type as the first element");
        vec_.insert(vec_.begin()+index, val);
    }
    
    void remove(size_t index, const T &value) {
        if (index > vec_.size())
            throw py::index_error();
        vec_.erase(vec_.begin()+index);
    }

    T& at(size_t index) {
        if (index > vec_.size())
            throw py::index_error();
        return vec_.at(index);
    }
    
    size_t size() const {
        return vec_.size();
    }

    void clear() {
        vec_.clear();
    }

    void print() {
        for (const auto &val: vec_) {
            std::cout << val << " ";
        }
        std::cout<<std::endl;
    }

private:
    std::vector<T> vec_;

};