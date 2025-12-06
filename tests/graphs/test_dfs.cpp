#include "../../include/graph/graph.h"
#include "../../include/graph/dfs.h"
#include <iostream>
#include <vector>

int main() {
    std::cout << "--- Testing DFS<int> ---\n\n";

    Graph<int> g(false, false); // undirected, unweighted

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    std::cout << "Graph adjacency list:\n";
    g.printGraph();

    auto order = DFS<int>::run(g, 1);

    std::cout << "DFS traversal starting from 1:\n";
    std::cout << "Actual  : ";
    for (int v : order) std::cout << v << " ";
    std::cout << "\nExpected (example DFS order): 1 2 4 3 5\n\n";

    // DFS from another node
    order = DFS<int>::run(g, 3);
    std::cout << "DFS traversal starting from 3:\n";
    std::cout << "Actual  : ";
    for (int v : order) std::cout << v << " ";
    std::cout << "\nExpected (example DFS order): 3 1 2 4 5\n";

    return 0;
}