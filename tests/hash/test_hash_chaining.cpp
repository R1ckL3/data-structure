#include <iostream>
#include "../../include/hash/hash_chaining.h"

int main() {
    ds::HashChaining<int, std::string> ht(5);

    ht.insert(1, "A");
    ht.insert(2, "B");
    ht.insert(12, "C"); // same bucket as 2

    ht.print();

    std::cout << "Find 1 -> Expected: Found, Actual: "
              << (ht.find(1) ? "Found" : "Not Found") << "\n";

    std::cout << "Find 99 -> Expected: Not Found, Actual: "
              << (ht.find(99) ? "Found" : "Not Found") << "\n";

    ht.remove(2);
    std::cout << "After removing key=2:\n";
    ht.print();

    return 0;
}