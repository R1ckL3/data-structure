#include <iostream>
#include "../../include/heaps/min_heap.h"

int main() {
    ds::MinHeap<int> heap;

    heap.insert(50);
    heap.insert(20);
    heap.insert(30);
    heap.insert(10);

    heap.print(); // 10 20 30 50

    std::cout << "Top -> Expected: 10, Actual: " << heap.top() << "\n";

    heap.pop();
    heap.print(); // 20 50 30
    std::cout << "Top after pop -> Expected: 20, Actual: " << heap.top() << "\n";

    return 0;
}