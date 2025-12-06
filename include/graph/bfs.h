#pragma once

/**
 * Breadth-First Search (BFS)
 *
 * Uses a queue to explore the graph level by level.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 *
 * Requires Graph adjacency list
 */

#include "graph.h"
#include <queue>
#include <unordered_map>
#include <vector>

template <typename T = int, typename W = int>
class BFS {
public:
    static std::vector<T> run(const Graph<T, W>& graph, const T& start) {
        if (!graph.hasVertex(start))
            throw std::runtime_error("BFS start vertex not found");

        std::unordered_map<T, bool> visited;
        std::queue<T> q;
        std::vector<T> order;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            T node = q.front();
            q.pop();
            order.push_back(node);

            for (const auto& edge : graph.neighbors(node)) {
                if (!visited[edge.to]) {
                    visited[edge.to] = true;
                    q.push(edge.to);
                }
            }
        }
        return order;
    }
};