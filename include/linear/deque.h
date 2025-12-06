#pragma once
/**
 * Deque (Double-Ended Queue)
 *
 * Operations:
 *  - push_front / push_back: O(1)
 *  - pop_front / pop_back:   O(1)
 *  - front / back:           O(1)
 *  - empty:                  O(1)
 *  
 */

#include <deque>
#include <stdexcept>
#include <iostream>

namespace ds {

template <typename T>
class Deque {
    public:
        Deque() = default;
        ~Deque() = default;

        void push_front(const T& value);
        void push_front(T&& value);

        void push_back(const T& value);
        void push_back(T&& value);

        void pop_front();
        void pop_back();

        T& front();
        const T& front() const;

        T& back();
        const T& back() const;

        bool empty() const noexcept { return container.empty(); }
        size_t size() const noexcept { return container.size(); }

        void print() const;

    private:
        std::deque<T> container;
};

template <typename T>
void Deque<T>::push_front(const T& value) { container.push_front(value); }

template <typename T>
void Deque<T>::push_front(T&& value) { container.push_front(std::move(value)); }

template <typename T>
void Deque<T>::push_back(const T& value) { container.push_back(value); }

template <typename T>
void Deque<T>::push_back(T&& value) { container.push_back(std::move(value)); }

template <typename T>
void Deque<T>::pop_front() {
    if (container.empty())
        throw std::out_of_range("Deque::pop_front: empty deque");
    container.pop_front();
}

template <typename T>
void Deque<T>::pop_back() {
    if (container.empty())
        throw std::out_of_range("Deque::pop_back: empty deque");
    container.pop_back();
}

template <typename T>
T& Deque<T>::front() {
    if (container.empty())
        throw std::out_of_range("Deque::front: empty deque");
    return container.front();
}

template <typename T>
const T& Deque<T>::front() const {
    if (container.empty())
        throw std::out_of_range("Deque::front: empty deque");
    return container.front();
}

template <typename T>
T& Deque<T>::back() {
    if (container.empty())
        throw std::out_of_range("Deque::back: empty deque");
    return container.back();
}

template <typename T>
const T& Deque<T>::back() const {
    if (container.empty())
        throw std::out_of_range("Deque::back: empty deque");
    return container.back();
}

template <typename T>
void Deque<T>::print() const {
    std::cout << "[";
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i];
        if (i + 1 < container.size()) std::cout << ", ";
    }
    std::cout << "] (front at left, back at right)\n";
}

}