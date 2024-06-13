#pragma once

#include <list>
#include <pybind11/pybind11.h>

namespace py = pybind11;

template <typename T>
class ListWrapper {
public:
    // Constructors
    ListWrapper() {}
    explicit ListWrapper(size_t size) : list(size) {}
    ListWrapper(size_t size, const T& value) : list(size, value) {}
    ListWrapper(std::list<T> init) : list(init) {}

    // Capacity
    size_t size() const { return list.size(); }
    bool empty() const { return list.empty(); }

    // Element access
    T& front() { 
        if (list.empty())
            throw std::out_of_range("List is empty!");
        return list.front(); 
    }
    T& back() { 
        if (list.empty())
            throw std::out_of_range("List is empty!");
        return list.back(); 
    }

    // Modifiers
    void push_back(const T& value) { list.push_back(value); }
    void push_front(const T& value) { list.push_front(value); }
    void pop_back() { 
        if (list.empty())
            throw std::out_of_range("List is empty!");
        list.pop_back(); 
    }
    void pop_front() { 
        if (list.empty())
            throw std::out_of_range("List is empty!");
        list.pop_front(); 
    }

    void insert(size_t index, const T& value) {
        if (index > list.size())
            throw std::out_of_range("Index out of range");
        auto it = std::next(list.begin(), index);
        list.insert(it, value);
    }
    
    void erase(size_t index) {
        if (index >= list.size())
            throw std::out_of_range("Index out of range");
        auto it = std::next(list.begin(), index);
        list.erase(it);
    }

    void clear() noexcept { list.clear(); }
    void swap(ListWrapper<T>& other) noexcept { list.swap(other.list); }

    // Iterators
    typename std::list<T>::iterator begin() noexcept { return list.begin(); }
    typename std::list<T>::const_iterator begin() const noexcept { return list.begin(); }
    typename std::list<T>::iterator end() noexcept { return list.end(); }
    typename std::list<T>::const_iterator end() const noexcept { return list.end(); }
    typename std::list<T>::reverse_iterator rbegin() noexcept { return list.rbegin(); }
    typename std::list<T>::const_reverse_iterator rbegin() const noexcept { return list.rbegin(); }
    typename std::list<T>::reverse_iterator rend() noexcept { return list.rend(); }
    typename std::list<T>::const_reverse_iterator rend() const noexcept { return list.rend(); }
    
    std::list<T>& getData() { return list; }
    size_t __len__() const { return list.size(); }

private:
    std::list<T> list;
};
