#include <iostream>
#include "../linear/stack.h"

int main() {
    ds::Stack<int> s;

    std::cout << "--- Testing Stack<int> ---\n";

    // Push
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << "After pushes: ";
    s.print();
    std::cout << "(expected: [10, 20, 30], top at right)\n\n";

    // Top
    std::cout << "Top: " << s.top() << " (expected: 30)\n\n";

    // Pop
    s.pop();
    std::cout << "After pop: ";
    s.print();
    std::cout << "(expected: [10, 20], top at right)\n\n";

    // Push more
    s.push(40);
    std::cout << "After push 40: ";
    s.print();
    std::cout << "(expected: [10, 20, 40], top at right)\n\n";

    // Top again
    std::cout << "Top: " << s.top() << " (expected: 40)\n";

    // Size & empty
    std::cout << "Size: " << s.size() << " (expected: 3)\n";
    std::cout << "Empty: " << (s.empty() ? "Yes" : "No") << " (expected: No)\n";

    return 0;
}