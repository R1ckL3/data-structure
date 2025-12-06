#include <iostream>
#include "../../include/trees/bst.h"

void check(bool condition, const std::string& action, const std::string& expected) {
    std::cout << action << " -> Expected: " << expected 
              << ", Actual: " << (condition ? "Found" : "Not Found") << "\n";
}

int main() {
    ds::BST<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    std::cout << "--- BST Inorder Traversal ---\n";
    bst.inorder(); // 20 30 40 50 70

    check(bst.search(40), "Searching 40", "Found");
    check(bst.search(99), "Searching 99", "Not Found");

    bst.remove(50);
    std::cout << "After removing 50:\n";
    bst.inorder(); // 20 30 40 70

    return 0;
}