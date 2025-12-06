#include "../../include/linear/queue.h"
#include <iostream>

int main() {
    std::cout << "--- Testing Linear Queue ---\n";
    ds::Queue<int> q(false);

    q.push(10);
    q.push(20);
    q.push(30);
    q.print();
    std::cout << "Expected: [10, 20, 30]\n";

    q.pop();
    q.print();
    std::cout << "Expected: [20, 30]\n";

    q.push(40);
    q.print();
    std::cout << "Expected: [20, 30, 40]\n\n";

    std::cout << "--- Testing Circular Queue ---\n";
    ds::Queue<int> cq(true, 3);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.print();
    std::cout << "Expected: [1, 2, 3]\n";

    std::cout << "Pop one element\n";
    cq.pop();
    cq.print();
    std::cout << "Expected: [2, 3]\n";

    std::cout << "Push 4 (wrap-around)\n";
    cq.push(4);
    cq.print();
    std::cout << "Expected: [2, 3, 4]\n";

    std::cout << "Front: " << cq.front() << " (expected: 2)\n";
    std::cout << "Back : " << cq.back() << " (expected: 4)\n";

    return 0;
}