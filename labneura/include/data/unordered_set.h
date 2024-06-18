#pragma once

#include <unordered_set>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

template <typename T>
class UnorderedSetWrapper {
public:
    using SetType = std::unordered_set<T>;

    // Constructors
    UnorderedSetWrapper() = default;
    UnorderedSetWrapper(const SetType& init) : set_(init) {}

    // Capacity
    size_t size() const {
        return set_.size();
    }

    bool empty() const {
        return set_.empty();
    }

    size_t max_size() const {
        return set_.max_size();
    }

    // Modifiers
    void clear() {
        set_.clear();
    }

    void insert(const T& value) {
        set_.insert(value);
    }

    void erase(const T& value) {
        set_.erase(value);
    }

    // Operations
    size_t count(const T& value) const {
        return set_.count(value);
    }

    bool contains(const T& value) const {
        return set_.find(value) != set_.end();
    }

    ssize_t find(const T& value) const {
        auto it = set_.find(value);
        if (it != set_.end()) {
            return std::distance(set_.begin(), it);
        }
        return -1;
    }

    // Bucket interface
    size_t bucket_count() const {
        return set_.bucket_count();
    }

    size_t bucket_size(size_t n) const {
        return set_.bucket_size(n);
    }

    size_t bucket(const T& value) const {
        return set_.bucket(value);
    }

    float load_factor() const {
        return set_.load_factor();
    }

    float max_load_factor() const {
        return set_.max_load_factor();
    }
    
    void rehash(size_t count) {
        set_.rehash(count);
    }

    void reserve(size_t count) {
        set_.reserve(count);
    }

    // Iterators
    typename SetType::iterator begin() {
        return set_.begin();
    }

    typename SetType::const_iterator begin() const {
        return set_.begin();
    }

    typename SetType::iterator end() {
        return set_.end();
    }

    typename SetType::const_iterator end() const {
        return set_.end();
    }

    typename SetType::const_iterator cbegin() const {
        return set_.cbegin();
    }

    typename SetType::const_iterator cend() const {
        return set_.cend();
    }

    typename SetType::iterator find_iterator(const T& value) {
        return set_.find(value);
    }

    std::vector<T> to_list() const {
        return std::vector<T>(set_.begin(), set_.end());
    }

private:
    SetType set_;
};