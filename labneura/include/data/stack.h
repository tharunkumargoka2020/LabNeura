#include <stack>
#include <iostream>

template<typename T>
class StackWrapper {
public:
    void push(const T& value) {
        stack_.push(value);
    }

    void pop() {
        if (!stack_.empty())
            stack_.pop();
        else
            throw std::runtime_error("Stack is empty");
    }

    T& top() {
        if (!stack_.empty())
            return stack_.top();
        else
            throw std::runtime_error("Stack is empty");
    }

    bool empty() const {
        return stack_.empty();
    }

    size_t size() const {
        return stack_.size();
    }

    void print() const {
        std::stack<T> temp = stack_;
        std::vector<T> elements;
        while (!temp.empty()) {
            elements.push_back(temp.top());
            temp.pop();
        }
        for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

private:
    std::stack<T> stack_;
};