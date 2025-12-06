#pragma once

/**
 * Depth-First Search (DFS)
 *
 * Uses recursion or a stack to explore the graph depth-first.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V) (recursion stack)
 *
 * Requires Graph adjacency list
 */

#include "graph.h"
#include <unordered_map>
#include <vector>

template <typename T = int, typename W = int>
class DFS {
    static void dfsUtil(const Graph<T, W>& graph, const T& node,
                        std::unordered_map<T, bool>& visited,
                        std::vector<T>& order) 
    {
        visited[node] = true;
        order.push_back(node);

        for (const auto& edge : graph.neighbors(node)) {
            if (!visited[edge.to]) {
                dfsUtil(graph, edge.to, visited, order);
            }
        }
    }

public:
    static std::vector<T> run(const Graph<T, W>& graph, const T& start) {
        if (!graph.hasVertex(start))
            throw std::runtime_error("DFS start vertex not found");

        std::unordered_map<T, bool> visited;
        std::vector<T> order;
        dfsUtil(graph, start, visited, order);
        return order;
    }
};