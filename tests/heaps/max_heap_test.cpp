#include <iostream>
#include "../../include/heaps/max_heap.h"

int main() {
    ds::MaxHeap<int> heap;

    heap.insert(50);
    heap.insert(20);
    heap.insert(30);
    heap.insert(10);

    heap.print(); // 50 20 30 10

    std::cout << "Top -> Expected: 50, Actual: " << heap.top() << "\n";

    heap.pop();
    heap.print(); // 30 20 10
    std::cout << "Top after pop -> Expected: 30, Actual: " << heap.top() << "\n";

    return 0;
}