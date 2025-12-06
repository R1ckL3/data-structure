#include <iostream>
#include "../deque.h"

int main() {
    ds::Deque<int> dq;

    std::cout << "--- Testing Deque<int> ---\n";

    // Push front/back
    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);
    dq.push_front(40);

    std::cout << "After pushes: ";
    dq.print();
    std::cout << "(expected: [40, 20, 10, 30], front at left, back at right)\n\n";

    // Front & Back
    std::cout << "Front: " << dq.front() << " (expected: 40)\n";
    std::cout << "Back: " << dq.back() << " (expected: 30)\n\n";

    // Pop front/back
    dq.pop_front();
    std::cout << "After pop_front: ";
    dq.print();
    std::cout << "(expected: [20, 10, 30])\n\n";

    dq.pop_back();
    std::cout << "After pop_back: ";
    dq.print();
    std::cout << "(expected: [20, 10])\n\n";

    // Size & Empty
    std::cout << "Size: " << dq.size() << " (expected: 2)\n";
    std::cout << "Empty: " << (dq.empty() ? "Yes" : "No") << " (expected: No)\n";

    return 0;
}