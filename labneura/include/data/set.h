#pragma once

#include <set>
#include <pybind11/pybind11.h>

namespace py = pybind11;

template <typename T>
class SetWrapper {
public:
    // Constructors
    SetWrapper() {}
    SetWrapper(const std::set<T>& init) : data(init) {}

    // Capacity
    size_t size() const { return data.size(); }
    bool empty() const { return data.empty(); }

    // Modifiers
    void insert(const T& value) { data.insert(value); }
    void erase(const T& value) { data.erase(value); }
    void clear() noexcept { data.clear(); }

    // Lookup
    bool contains(const T& value) const { return data.find(value) != data.end(); }
    ssize_t find(const T& value) const {
        auto it = data.find(value);
        if (it != data.end()) {
            return std::distance(data.begin(), it);
        }
        return -1;
    }

    // Iterators
    typename std::set<T>::iterator begin() noexcept { return data.begin(); }
    typename std::set<T>::iterator end() noexcept { return data.end(); }
    typename std::set<T>::const_iterator begin() const noexcept { return data.begin(); }
    typename std::set<T>::const_iterator end() const noexcept { return data.end(); }

    std::set<T>& getData() { return data; }

private:
    std::set<T> data;
};
