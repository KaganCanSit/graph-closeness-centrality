#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"
#include <vector>
#include <limits>
#include <queue>
#include <functional>

class Dijkstra {
private:
    const Graph& graph;
    
public:
    Dijkstra(const Graph& g) : graph(g) {}
    
    // λ (lambda) represents the distance vector
    // T represents the set of vertices to be visited
    // P represents parent nodes
    std::vector<int> shortestPath(int start, std::vector<int>& lambda, std::vector<int>& P);
    
    // Calculate closeness centrality for all vertices
    std::vector<double> calculateClosenessCentrality();
};

#endif // DIJKSTRA_H 