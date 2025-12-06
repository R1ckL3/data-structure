#include <iostream>
#include "../linear/singly_linked_list.h"

int main() {
    ds::SinglyLinkedList<int> list;

    std::cout << "--- Testing SinglyLinkedList<int> ---\n";

    // Push front/back
    list.push_front(10);
    list.push_front(20);
    list.push_back(30);
    list.push_back(40);

    std::cout << "After pushes: ";
    list.print();
    std::cout << "(expected: [20, 10, 30, 40])\n\n";

    // Pop front
    list.pop_front();
    std::cout << "After pop_front: ";
    list.print();
    std::cout << "(expected: [10, 30, 40])\n\n";

    // Pop back
    list.pop_back();
    std::cout << "After pop_back: ";
    list.print();
    std::cout << "(expected: [10, 30])\n\n";

    // Search
    std::cout << "Searching 10: ";
    std::cout << (list.search(10) ? "Found" : "Not Found");
    std::cout << " (expected: Found)\n";

    std::cout << "Searching 999: ";
    std::cout << (list.search(999) ? "Found" : "Not Found");
    std::cout << " (expected: Not Found)\n\n";

    // Remove
    list.remove(10);
    std::cout << "After remove 10: ";
    list.print();
    std::cout << "(expected: [30])\n\n";

    // Size
    std::cout << "Size: " << list.size() << " (expected: 1)\n";

    return 0;
}