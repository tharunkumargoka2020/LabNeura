#pragma once

#include <deque>
#include <pybind11/pybind11.h>

namespace py = pybind11;

template <typename T>
class DequeWrapper {
public:
    // Constructors
    DequeWrapper() {}
    explicit DequeWrapper(size_t size) : deque(size) {}
    DequeWrapper(size_t size, const T& value) : deque(size, value) {}
    DequeWrapper(std::deque<T> init) : deque(init) {}
    
    // Capacity
    size_t size() const { return deque.size(); }
    size_t max_size() const { return deque.max_size(); }
    void resize(size_t count) { deque.resize(count); }
    bool empty() const { return deque.empty(); }
    void shrink_to_fit() { deque.shrink_to_fit(); }
    
    // Element access
    T& at(size_t index) { 
        if (index >= deque.size())
            throw std::out_of_range("Index out of range");
        return deque.at(index); 
    }
    T& operator[](size_t index) { 
        if (index >= deque.size())
            throw std::out_of_range("Index out of range");
        return deque[index]; 
    }
    T& front() { 
        if (deque.empty())
            throw std::out_of_range("Deque is empty!");
        return deque.front(); 
    }
    T& back() { 
        if (deque.empty())
            throw std::out_of_range("Deque is empty!"); 
        return deque.back(); 
    }
    
    // Modifiers
    void push_back(const T& value) { deque.push_back(value); }
    void push_front(const T& value) { deque.push_front(value); }
    void pop_back() { 
        if (!deque.empty())
            deque.pop_back(); 
        else
            throw std::out_of_range("Deque is empty!");
    }
    void pop_front() { 
        if (!deque.empty())
            deque.pop_front(); 
        else
            throw std::out_of_range("Deque is empty!");
    }
    void insert(size_t index, const T& value) {
        if (index > deque.size())
            throw std::out_of_range("Index out of range");
        deque.insert(deque.begin() + index, value);
    }

    void erase(size_t index) {
        if (index >= deque.size())
            throw std::out_of_range("Index out of range");
        deque.erase(deque.begin() + index);
    }

    void clear() noexcept { deque.clear(); }
    void swap(DequeWrapper<T>& other) noexcept { deque.swap(other.deque); }
    
    // Iterators
    typename std::deque<T>::iterator begin() noexcept { return deque.begin(); }
    typename std::deque<T>::const_iterator begin() const noexcept { return deque.begin(); }
    typename std::deque<T>::iterator end() noexcept { return deque.end(); }
    typename std::deque<T>::const_iterator end() const noexcept { return deque.end(); }
    typename std::deque<T>::reverse_iterator rbegin() noexcept { return deque.rbegin(); }
    typename std::deque<T>::const_reverse_iterator rbegin() const noexcept { return deque.rbegin(); }
    typename std::deque<T>::reverse_iterator rend() noexcept { return deque.rend(); }
    typename std::deque<T>::const_reverse_iterator rend() const noexcept { return deque.rend(); }
    typename std::deque<T>::const_iterator cbegin() const noexcept { return deque.cbegin(); }
    typename std::deque<T>::const_iterator cend() const noexcept { return deque.cend(); }
    typename std::deque<T>::const_reverse_iterator crbegin() const noexcept { return deque.crbegin(); }
    typename std::deque<T>::const_reverse_iterator crend() const noexcept { return deque.crend(); }
    
    std::deque<T>& getData() { return deque; }
    size_t __len__() const { return deque.size(); }

private:
    std::deque<T> deque;
};
