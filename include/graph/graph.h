#pragma once

/**
 * Graph (Adjacency List)
 *
 * Supports directed/undirected and weighted/unweighted graphs.
 * Operations:
 *  - addVertex: O(1)
 *  - addEdge:   O(1) average per edge
 *  - removeEdge: O(degree(v)) for undirected, O(degree(from)) for directed
 *  - hasVertex: O(1)
 *  - hasEdge:   O(degree(from))
 *  - neighbors: O(1)
 *  - vertices:  O(V)
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <algorithm>
#include <limits>

template <typename T = int, typename W = int>
class Graph {
public:
    struct Edge {
        T to;
        W weight;
    };

private:
    bool directed;
    bool weighted;

    std::unordered_map<T, std::vector<Edge>> adj;

public:
    Graph(bool directed = false, bool weighted = false)
        : directed(directed), weighted(weighted) {}

    void addVertex(const T& v) {
        adj.emplace(v, std::vector<Edge>());
    }

    void addEdge(const T& from, const T& to, const W& weight = W(1)) {
        if (!weighted && weight != W(1))
            throw std::runtime_error("Cannot add weighted edge to an unweighted graph");

        if (!adj.count(from))
            addVertex(from);
        if (!adj.count(to))
            addVertex(to);

        adj[from].push_back({to, weight});

        if (!directed)
            adj[to].push_back({from, weight});
    }

    bool hasVertex(const T& v) const {
        return adj.count(v) > 0;
    }

    const std::vector<Edge>& neighbors(const T& v) const {
        if (!adj.count(v))
            throw std::runtime_error("Vertex not found");
        return adj.at(v);
    }
    bool hasEdge(const T& from, const T& to) const {
        if (!adj.count(from))
            return false;

        for (const auto& edge : adj.at(from)) {
            if (edge.to == to)
                return true;
        }
        return false;
    }
    void printGraph() const {
        std::cout << (directed ? "Directed" : "Undirected")
                << (weighted ? " Weighted" : " Unweighted")
                << " Graph\n";

        for (const auto& [v, edges] : adj) {
            std::cout << v << " -> ";

            if (edges.empty()) {
                std::cout << "{}\n";
                continue;
            }

            std::cout << "{ ";
            for (const auto& e : edges) {
                if (weighted)
                    std::cout << e.to << "(" << e.weight << ") ";
                else
                    std::cout << e.to << " ";
            }
            std::cout << "}\n";
        }

        std::cout << "\n";
    }
    
    std::vector<T> vertices() const {
        std::vector<T> list;
        list.reserve(adj.size());
        for (const auto& p : adj)
            list.push_back(p.first);
        return list;
    }

    bool isDirected() const { return directed; }
    bool isWeighted() const { return weighted; }

    void removeEdge(const T& from, const T& to) {
        if (!adj.count(from) || !adj.count(to))
            return;

        auto& list = adj[from];
        list.erase(
            std::remove_if(list.begin(), list.end(),
                           [&](const Edge& e){ return e.to == to; }),
            list.end()
        );

        if (!directed) {
            auto& back = adj[to];
            back.erase(
                std::remove_if(back.begin(), back.end(),
                               [&](const Edge& e){ return e.to == from; }),
                back.end()
            );
        }
    }
};