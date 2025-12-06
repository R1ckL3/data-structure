#pragma once

/**
 * Max-Heap
 *
 * Binary heap where the largest element is at the root.
 *
 * Operations:
 *  - insert:   O(log n)
 *  - extract:  O(log n)
 *  - peek:     O(1)
 *
 */

#include <vector>
#include <iostream>

namespace ds {

template <typename T>
class MaxHeap {
public:
    MaxHeap() {}
    
    void insert(const T& value);
    void pop();
    T top() const;
    bool empty() const { return heap.empty(); }
    void print() const;

private:
    std::vector<T> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);
};

template <typename T>
void MaxHeap<T>::insert(const T& value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

template <typename T>
void MaxHeap<T>::pop() {
    if (heap.empty()) return;
    std::swap(heap.front(), heap.back());
    heap.pop_back();
    if (!heap.empty()) heapifyDown(0);
}

template <typename T>
T MaxHeap<T>::top() const {
    if (!heap.empty()) return heap.front();
    throw std::runtime_error("Heap is empty");
}

template <typename T>
void MaxHeap<T>::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] >= heap[index]) break;
        std::swap(heap[parent], heap[index]);
        index = parent;
    }
}

template <typename T>
void MaxHeap<T>::heapifyDown(int index) {
    int left, right, largest;
    while (true) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        largest = index;

        if (left < heap.size() && heap[left] > heap[largest]) largest = left;
        if (right < heap.size() && heap[right] > heap[largest]) largest = right;

        if (largest == index) break;
        std::swap(heap[index], heap[largest]);
        index = largest;
    }
}

template <typename T>
void MaxHeap<T>::print() const {
    std::cout << "MaxHeap: ";
    for (const auto& val : heap) std::cout << val << " ";
    std::cout << "\n";
}

}