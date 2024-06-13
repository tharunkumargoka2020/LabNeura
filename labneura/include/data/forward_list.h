#pragma once

#include <forward_list>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

template <typename T>
class ForwardListWrapper {
public:
    // Constructors
    ForwardListWrapper() {}
    explicit ForwardListWrapper(size_t count, const T& value = T()) : forward_list(count, value) {}
    ForwardListWrapper(std::forward_list<T> init) : forward_list(init) {}

    // Capacity
    bool empty() const { return forward_list.empty(); }

    // Element access
    T& front() {
        if (forward_list.empty()) throw std::out_of_range("Forward list is empty!");
        return forward_list.front();
    }

    // Modifiers
    void push_front(const T& value) { forward_list.push_front(value); }
    void pop_front() {
        if (forward_list.empty()) throw std::out_of_range("Forward list is empty!");
        forward_list.pop_front();
    }
    void clear() noexcept { forward_list.clear(); }
    void insert_after(size_t pos, const T& value) {
        auto it = advance_and_get_iterator(pos);
        forward_list.insert_after(it, value);
    }
    void erase_after(size_t pos) {
        auto it = advance_and_get_iterator(pos);
        if (std::next(it) == forward_list.end()) throw std::out_of_range("No element to erase!");
        forward_list.erase_after(it);
    }

    // Iterators
    typename std::forward_list<T>::iterator begin() noexcept { return forward_list.begin(); }
    typename std::forward_list<T>::const_iterator begin() const noexcept { return forward_list.begin(); }
    typename std::forward_list<T>::iterator end() noexcept { return forward_list.end(); }
    typename std::forward_list<T>::const_iterator end() const noexcept { return forward_list.end(); }
    typename std::forward_list<T>::const_iterator cbegin() const noexcept { return forward_list.cbegin(); }
    typename std::forward_list<T>::const_iterator cend() const noexcept { return forward_list.cend(); }

    std::forward_list<T>& getData() { return forward_list; }

private:
    std::forward_list<T> forward_list;

    typename std::forward_list<T>::iterator advance_and_get_iterator(size_t pos) {
        auto it = forward_list.before_begin();
        for (size_t i = 0; i <= pos; ++i) {
            if (std::next(it) == forward_list.end()) throw std::out_of_range("Position out of range!");
            ++it;
        }
        return it;
    }
};
