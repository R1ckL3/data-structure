#include "../../include/graph/graph.h"
#include "../../include/graph/bfs.h"
#include <iostream>
#include <vector>

int main() {
    std::cout << "--- Testing BFS<int> ---\n\n";

    Graph<int> g(false, false); // undirected, unweighted

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    std::cout << "Graph adjacency list:\n";
    g.printGraph();

    auto order = BFS<int>::run(g, 1);

    std::cout << "BFS traversal starting from 1:\n";
    std::cout << "Actual  : ";
    for (int v : order) std::cout << v << " ";
    std::cout << "\nExpected: 1 2 3 4 5\n\n";

    // BFS from another node
    order = BFS<int>::run(g, 3);
    std::cout << "BFS traversal starting from 3:\n";
    std::cout << "Actual  : ";
    for (int v : order) std::cout << v << " ";
    std::cout << "\nExpected: 3 1 5 2 4\n";

    return 0;
}