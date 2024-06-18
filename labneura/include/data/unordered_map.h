#pragma once

#include <unordered_map>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

template <typename Key, typename T>
class UnorderedMapWrapper {
public:
    using MapType = std::unordered_map<Key, T>;
    UnorderedMapWrapper() = default;

    // Element Access
    T& at(const Key& key) {
        if (umap.find(key) == umap.end()) {
            throw std::out_of_range("Key not found");
        }
        return umap.at(key);
    }

    T& operator[](const Key& key) { return umap[key]; }

    // Modifiers
    void insert(const Key& key, const T& value) { umap[key] = value; }
    void erase(const Key& key) { umap.erase(key); }
    void clear() { umap.clear(); }
    
    
    // Lookup
    bool contains(const Key& key) const { return umap.find(key) != umap.end(); }
    ssize_t find(const Key& key) const {
        auto it = umap.find(key);
        if (it == umap.end()) return -1;
        return std::distance(umap.begin(), it);
    }

    void setItem(const Key& key, const T& value) {
        umap[key] = value;
    }

    T getItem(const Key& key) const {
        auto it = umap.find(key);
        if (it == umap.end()) {
            throw std::out_of_range("Key not found in map");
        }
        return it->second;
    }

    void deleteItem(const Key& key) {
        auto it = umap.find(key);
        if (it == umap.end()) {
            throw std::out_of_range("Key not found in map");
        }
        umap.erase(it);
    }

    py::list items() const {
        py::list items;
        for (const auto& kv : umap) {
            items.append(py::make_tuple(kv.first, kv.second));
        }
        return items;
    }

    // Bucket Interface
    size_t bucket_count() const { return umap.bucket_count(); }
    size_t bucket_size(size_t n) const { return umap.bucket_size(n); }
    size_t bucket(const Key& key) const { return umap.bucket(key); }

    // Hash Policy
    float load_factor() const { return umap.load_factor(); }
    float max_load_factor() const { return umap.max_load_factor(); }
    void rehash(size_t n) { umap.rehash(n); }
    void reserve(size_t n) { umap.reserve(n); }

    // Iterators
    typename MapType::iterator begin() noexcept { return umap.begin(); }
    typename MapType::iterator end() noexcept { return umap.end(); }
    typename MapType::const_iterator begin() const noexcept { return umap.begin(); }
    typename MapType::const_iterator end() const noexcept { return umap.end(); }

    size_t size() const { return umap.size(); }
    bool empty() const { return umap.empty(); }
    std::unordered_map<Key, T>& getData() { return umap; }

private:
    std::unordered_map<Key, T> umap;
};
