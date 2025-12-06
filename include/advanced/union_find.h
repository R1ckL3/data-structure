#pragma once
/**
 * Union-Find / Disjoint Set
 *
 * Operations:
 *  - find:    O(alpha(n)) amortized
 *  - unite:   O(alpha(n)) amortized
 *  - connected: O(alpha(n))
 *
 */

#include <vector>
#include <iostream>

namespace ds {

template <typename T = int>
class UnionFind {
public:
    UnionFind(size_t n) : parent(n), rank(n, 0) {
        for (size_t i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Find with path compression
    T find(T x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by rank
    void unite(T x, T y) {
        T px = find(x);
        T py = find(y);
        if (px == py) return;

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    // Check if connected
    bool connected(T x, T y) {
        return find(x) == find(y);
    }

    // Print parents (for testing)
    void print() const {
        std::cout << "Parents: [";
        for (size_t i = 0; i < parent.size(); ++i) {
            std::cout << parent[i];
            if (i + 1 < parent.size()) std::cout << ", ";
        }
        std::cout << "]\n";
    }

private:
    std::vector<T> parent;
    std::vector<int> rank;
};

}