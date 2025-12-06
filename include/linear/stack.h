#pragma once
/**
 * Stack (LIFO)
 *
 * Operations:
 *  - push:    O(1)
 *  - pop:     O(1)
 *  - top:     O(1)
 *  - empty:   O(1)
 *
 */

#include <vector>
#include <stdexcept>
#include <iostream>

namespace ds {

template <typename T>
class Stack {
    public:
        Stack() = default;
        ~Stack() = default;

        void push(const T& value);
        void push(T&& value);

        void pop();
        T& top();
        const T& top() const;

        bool empty() const noexcept { return container.empty(); }
        size_t size() const noexcept { return container.size(); }

        void print() const;

    private:
        std::vector<T> container;
};


template <typename T>
void Stack<T>::push(const T& value) {
    container.push_back(value);
}

template <typename T>
void Stack<T>::push(T&& value) {
    container.push_back(std::move(value));
}

template <typename T>
void Stack<T>::pop() {
    if (container.empty())
        throw std::out_of_range("Stack::pop: empty stack");
    container.pop_back();
}

template <typename T>
T& Stack<T>::top() {
    if (container.empty())
        throw std::out_of_range("Stack::top: empty stack");
    return container.back();
}

template <typename T>
const T& Stack<T>::top() const {
    if (container.empty())
        throw std::out_of_range("Stack::top: empty stack");
    return container.back();
}

template <typename T>
void Stack<T>::print() const {
    std::cout << "[";
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i];
        if (i + 1 < container.size()) std::cout << ", ";
    }
    std::cout << "] (top at right)\n";
}

}