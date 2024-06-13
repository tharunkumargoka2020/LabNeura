#pragma once

#include <vector>
#include <pybind11/pybind11.h>

namespace py = pybind11;

template <typename T>
class VectorWrapper {
public:
    // Constructors
    VectorWrapper() {}
    explicit VectorWrapper(size_t size) : vec(size) {}
    VectorWrapper(size_t size, const T& value) : vec(size, value) {}
    VectorWrapper(std::vector<T> init) : vec(init) {}
    
    // Capacity
    size_t size() const { return vec.size(); }
    size_t max_size() const { return vec.max_size(); }
    void resize(size_t count) { vec.resize(count); }
    size_t capacity() const { return vec.capacity(); }
    bool empty() const { return vec.empty(); }
    void reserve(size_t new_cap) { vec.reserve(new_cap); }
    void shrink_to_fit() { vec.shrink_to_fit(); }
    
    // Element access
    T& at(size_t index) { 
        if (index>size())
            throw std::out_of_range("Index out of range");
        return vec.at(index); 
    }
    T& operator[](size_t index) { 
        if (index>size())
            throw std::out_of_range("Index out of range");
        return vec[index]; 
    }
    T& front() { 
        if (!empty())
            return vec.front(); 
        throw std::out_of_range("Vector is empty!");
    }
    T& back() { 
        if (!empty())
            return vec.back();
        throw std::out_of_range("Vector is empty!"); 
    }
    
    // Modifiers
    void push_back(T&& value) { vec.push_back(std::move(value)); }
    void pop_back() { 
        if (!empty())
            vec.pop_back(); 
        else
            throw std::out_of_range("Vector is empty!");
    }
    void insert(size_t index, const T& value) {
        if (index > vec.size())
            throw std::out_of_range("Index out of range");
        vec.insert(vec.begin() + index, value);
    }

    void erase(size_t index) {
        if (index >= vec.size())
            throw std::out_of_range("Index out of range");
        vec.erase(vec.begin() + index);
    }


    void clear() noexcept { vec.clear(); }
    void swap(VectorWrapper<T>& other) noexcept { vec.swap(other.vec); }
    
    // Iterators
    typename std::vector<T>::iterator begin() noexcept { return vec.begin(); }
    typename std::vector<T>::const_iterator begin() const noexcept { return vec.begin(); }
    typename std::vector<T>::iterator end() noexcept { return vec.end(); }
    typename std::vector<T>::const_iterator end() const noexcept { return vec.end(); }
    typename std::vector<T>::reverse_iterator rbegin() noexcept { return vec.rbegin(); }
    typename std::vector<T>::const_reverse_iterator rbegin() const noexcept { return vec.rbegin(); }
    typename std::vector<T>::reverse_iterator rend() noexcept { return vec.rend(); }
    typename std::vector<T>::const_reverse_iterator rend() const noexcept { return vec.rend(); }
    typename std::vector<T>::const_iterator cbegin() const noexcept { return vec.cbegin(); }
    typename std::vector<T>::const_iterator cend() const noexcept { return vec.cend(); }
    typename std::vector<T>::const_reverse_iterator crbegin() const noexcept { return vec.crbegin(); }
    typename std::vector<T>::const_reverse_iterator crend() const noexcept { return vec.crend(); }
    
    std::vector<T>& getData() { return vec; }
    size_t __len__() const { return vec.size(); }

private:
    std::vector<T> vec;
};
