#include <iostream>
#include "../../include/graph/graph.h"

int main() {
    std::cout << "--- Testing Graph<int,int> ---\n\n";

    // Undirected, unweighted
    Graph<int, int> g(false, false);

    std::cout << "Adding vertices 1, 2, 3\n";
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);

    std::cout << "Adding edges: 1-2, 2-3\n";
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    std::cout << "\nGraph print (expected undirected 1<->2<->3 chain):\n";
    g.printGraph();

    // Check neighbors
    std::cout << "\nNeighbors of 2 (expected: 1, 3): ";
    for (auto &e : g.neighbors(2))
        std::cout << e.to << " ";
    std::cout << "\n";

    // Directed weighted
    std::cout << "\n--- Testing Directed Weighted Graph<char,double> ---\n\n";

    Graph<char, double> dg(true, true);

    dg.addEdge('A', 'B', 1.5);
    dg.addEdge('A', 'C', 2.3);
    dg.addEdge('B', 'D', 5.0);

    std::cout << "Graph print (expected directed A->B, A->C, B->D with weights):\n";
    dg.printGraph();

    std::cout << "\nNeighbors of A (expected: B(1.5), C(2.3)): ";
    for (auto &e : dg.neighbors('A'))
        std::cout << e.to << "(" << e.weight << ") ";
    std::cout << "\n";

    // hasVertex + hasEdge
    std::cout << "\nCheck vertices and edges:\n";
    std::cout << "hasVertex('C') -> " 
              << (dg.hasVertex('C') ? "true" : "false") 
              << " (expected: true)\n";

    std::cout << "hasEdge(A->D) -> " 
              << (dg.hasEdge('A','D') ? "true" : "false") 
              << " (expected: false)\n";

    std::cout << "hasEdge(B->D) -> " 
              << (dg.hasEdge('B','D') ? "true" : "false") 
              << " (expected: true)\n";

    return 0;
}