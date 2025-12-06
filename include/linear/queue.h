#pragma once
/**
 * Queue (FIFO) with optional Circular mode
 *
 * Operations:
 *  - push:    O(1)
 *  - pop:     O(1)
 *  - front:   O(1)
 *  - back:    O(1)
 *  - size:    O(1)
 *  - empty:   O(1)
 */

#include <vector>
#include <stdexcept>
#include <iostream>

namespace ds {

template <typename T>
class Queue {
public:
    explicit Queue(bool circular = false, size_t capacity = 100)
        : circular(circular), capacity(capacity), frontIdx(0), rearIdx(0), count(0)
    {
        if (circular)
            data.resize(capacity);
    }

    void push(const T& value) {
        if (!circular) {
            linearData.push_back(value);
        } else {
            if (count == capacity)
                throw std::overflow_error("Circular Queue full");
            data[rearIdx] = value;
            rearIdx = (rearIdx + 1) % capacity;
            count++;
        }
    }

    void push(T&& value) {
        if (!circular) {
            linearData.push_back(std::move(value));
        } else {
            if (count == capacity)
                throw std::overflow_error("Circular Queue full");
            data[rearIdx] = std::move(value);
            rearIdx = (rearIdx + 1) % capacity;
            count++;
        }
    }

    void pop() {
        if (empty())
            throw std::out_of_range("Queue::pop(): empty queue");
        if (!circular) {
            linearData.erase(linearData.begin());
        } else {
            frontIdx = (frontIdx + 1) % capacity;
            count--;
        }
    }

    T& front() {
        if (empty())
            throw std::out_of_range("Queue::front(): empty queue");
        return circular ? data[frontIdx] : linearData.front();
    }

    const T& front() const {
        if (empty())
            throw std::out_of_range("Queue::front(): empty queue");
        return circular ? data[frontIdx] : linearData.front();
    }

    T& back() {
        if (empty())
            throw std::out_of_range("Queue::back(): empty queue");
        return circular ? data[(rearIdx + capacity - 1) % capacity] : linearData.back();
    }

    const T& back() const {
        if (empty())
            throw std::out_of_range("Queue::back(): empty queue");
        return circular ? data[(rearIdx + capacity - 1) % capacity] : linearData.back();
    }

    bool empty() const noexcept {
        return circular ? (count == 0) : linearData.empty();
    }

    size_t size() const noexcept {
        return circular ? count : linearData.size();
    }

    void clear() noexcept {
        if (!circular)
            linearData.clear();
        else {
            frontIdx = 0;
            rearIdx = 0;
            count = 0;
        }
    }

    void print() const {
        std::cout << "[";
        if (!circular) {
            for (size_t i = 0; i < linearData.size(); ++i) {
                std::cout << linearData[i];
                if (i + 1 < linearData.size()) std::cout << ", ";
            }
        } else {
            for (size_t i = 0; i < count; ++i) {
                size_t idx = (frontIdx + i) % capacity;
                std::cout << data[idx];
                if (i + 1 < count) std::cout << ", ";
            }
        }
        std::cout << "] (front at left)\n";
    }

private:
    bool circular;
    size_t capacity;

    // Linear mode storage
    std::vector<T> linearData;

    // Circular mode storage
    std::vector<T> data;
    size_t frontIdx;
    size_t rearIdx;
    size_t count;
};

}