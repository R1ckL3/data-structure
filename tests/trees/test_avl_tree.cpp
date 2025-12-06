#include <iostream>
#include "../../include/trees/avl_tree.h"

void check(bool condition, const std::string& action, const std::string& expected) {
    std::cout << action << " -> Expected: " << expected 
              << ", Actual: " << (condition ? "Found" : "Not Found") << "\n";
}

// Helper to print rotations (requires minor change in avl_tree.h to optionally log)
void printInorder(ds::AVL<int>& avl, const std::string& msg) {
    std::cout << msg << ": ";
    avl.inorder();
}

int main() {
    ds::AVL<int> avl;

    std::cout << "--- Inserting nodes (rotation visualization) ---\n";

    avl.insert(50); printInorder(avl, "After inserting 50"); // 50
    avl.insert(30); printInorder(avl, "After inserting 30"); // 30 50
    avl.insert(70); printInorder(avl, "After inserting 70"); // 30 50 70
    avl.insert(20); printInorder(avl, "After inserting 20"); // 20 30 50 70
    avl.insert(40); printInorder(avl, "After inserting 40"); // 20 30 40 50 70
    avl.insert(60); printInorder(avl, "After inserting 60"); // 20 30 40 50 60 70
    avl.insert(80); printInorder(avl, "After inserting 80"); // 20 30 40 50 60 70 80

    std::cout << "\n--- Searching nodes ---\n";
    check(avl.search(40), "Searching 40", "Found");
    check(avl.search(99), "Searching 99", "Not Found");

    std::cout << "\n--- Removing node 50 (root) ---\n";
    avl.remove(50);
    printInorder(avl, "After removing 50"); // 20 30 40 60 70 80

    std::cout << "\n--- Removing node 20 (leaf) ---\n";
    avl.remove(20);
    printInorder(avl, "After removing 20"); // 30 40 60 70 80

    std::cout << "\n--- Removing node 30 (node with one child) ---\n";
    avl.remove(30);
    printInorder(avl, "After removing 30"); // 40 60 70 80

    return 0;
}