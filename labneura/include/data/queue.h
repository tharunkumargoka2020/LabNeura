#pragma once

#include <queue>
#include <iostream>

template<typename T>
class QueueWrapper {
public:
    void push(const T& value) {
        queue_.push(value);
    }

    void pop() {
        if (!queue_.empty())
            queue_.pop();
        else
            throw std::runtime_error("Queue is empty");
    }

    T& front() {
        if (!queue_.empty())
            return queue_.front();
        throw std::runtime_error("Queue is empty");
    }

    bool empty() const {
        return queue_.empty();
    }

    size_t size() const {
        return queue_.size();
    }

    void print() const {
        std::queue<T> temp = queue_;
        while (!temp.empty()) {
            std::cout << temp.front() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }

private:
    std::queue<T> queue_;
};
