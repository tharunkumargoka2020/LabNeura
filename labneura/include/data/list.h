#pragma once

#include <list>
#include <iostream>

template<typename T>
class ListWrapper {
public:
    void push_back(const T& value) {
        list_.push_back(value);
    }

    T& at(size_t index) {
        auto it = list_.begin();
        std::advance(it, index); 
        return *it;
    }

    void pop_back() {
        if (!list_.empty())
            list_.pop_back();
        throw std::runtime_error("List is empty");
    }

    T& back() {
        if (!list_.empty())
            return list_.back();
        throw std::runtime_error("List is empty");
    }

    bool empty() const {
        return list_.empty();
    }

    size_t size() const {
        return list_.size();
    }

    void insert(size_t index, const T& value) {
        auto it = std::next(list_.begin(), index);
        list_.insert(it, value);
    }

    void remove(size_t index) {
        if (!list_.empty()){
            auto it = std::next(list_.begin(), index);
            list_.erase(it);
        }
        throw std::runtime_error("List is empty");
    }

    void print() const {
        for (const auto& item : list_) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

private:
    std::list<T> list_;
};
