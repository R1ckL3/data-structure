#include "../../include/advanced/union_find.h"
#include <iostream>

int main() {
    std::cout << "--- Testing UnionFind ---\n\n";

    ds::UnionFind<int> uf(10);

    std::cout << "Initially:\n";
    uf.print();
    std::cout << "Expected: 0 1 2 3 4 5 6 7 8 9\n\n";

    std::cout << "Unite 1 & 2, 2 & 5, 5 & 6\n";
    uf.unite(1, 2);
    uf.unite(2, 5);
    uf.unite(5, 6);
    uf.print();
    std::cout << "Expected: 1,1,1,3,4,1,1,7,8,9 (or similar, depends on rank)\n\n";

    std::cout << "Check connections:\n";
    std::cout << "connected(1,6): " << (uf.connected(1,6) ? "Yes" : "No") << " (expected: Yes)\n";
    std::cout << "connected(0,1): " << (uf.connected(0,1) ? "Yes" : "No") << " (expected: No)\n";

    std::cout << "\nUnite 0 & 1\n";
    uf.unite(0,1);
    uf.print();
    std::cout << "connected(0,6): " << (uf.connected(0,6) ? "Yes" : "No") << " (expected: Yes)\n";

    return 0;
}