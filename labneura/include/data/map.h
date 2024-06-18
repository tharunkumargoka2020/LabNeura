#pragma once

#include <map>
#include <pybind11/pybind11.h>

namespace py = pybind11;

template <typename Key, typename T>
class MapWrapper {
public:
    // Constructors
    MapWrapper() {}
    MapWrapper(const std::map<Key, T>& init) : map(init) {}

    // Capacity
    size_t size() const { return map.size(); }
    bool empty() const { return map.empty(); }

    // Modifiers
    void clear() noexcept { map.clear(); }
    void insert(const Key& key, const T& value) { map[key] = value; }
    void erase(const Key& key) { map.erase(key); }

    // Lookup
    T at(const Key& key) { return map.at(key); }
    T& operator[](const Key& key) { return map[key]; }

    void setItem(const Key& key, const T& value) {
        map[key] = value;
    }

    T getItem(const Key& key) const {
        auto it = map.find(key);
        if (it == map.end()) {
            throw std::out_of_range("Key not found in map");
        }
        return it->second;
    }

    void deleteItem(const Key& key) {
        auto it = map.find(key);
        if (it == map.end()) {
            throw std::out_of_range("Key not found in map");
        }
        map.erase(it);
    }

    bool contains(const Key& key) const {
        return map.find(key) != map.end();
    }

    ssize_t find(const Key& key) const {
        auto it = map.find(key);
        if (it != map.end()) {
            return std::distance(map.begin(), it);
        }
        return -1;
    }

    py::list items() const {
        py::list items;
        for (const auto& kv : map) {
            items.append(py::make_tuple(kv.first, kv.second));
        }
        return items;
    }

    // Iterators
    typename std::map<Key, T>::iterator begin() noexcept { return map.begin(); }
    typename std::map<Key, T>::iterator end() noexcept { return map.end(); }
    typename std::map<Key, T>::const_iterator begin() const noexcept { return map.begin(); }
    typename std::map<Key, T>::const_iterator end() const noexcept { return map.end(); }

    std::map<Key, T>& getData() { return map; }

private:
    std::map<Key, T> map;
};
