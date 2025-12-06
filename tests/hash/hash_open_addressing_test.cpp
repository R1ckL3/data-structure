#include <iostream>
#include "../../include/hash/hash_open_addressing.h"

int main() {
    ds::HashOpenAddressing<int, std::string> ht(5);

    ht.insert(1, "A");
    ht.insert(6, "B"); // collision, linear probing
    ht.insert(11, "C");

    ht.print();

    std::cout << "Find 6 -> Expected: Found, Actual: "
              << (ht.find(6) ? "Found" : "Not Found") << "\n";

    ht.remove(6);
    std::cout << "After removing 6:\n";
    ht.print();

    return 0;
}