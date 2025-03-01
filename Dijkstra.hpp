#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <queue>
#include <limits>

#include "Graph.hpp"

class Dijkstra {
public:
    static std::vector<int> shortestPath(int start, const Graph& graph);
};

#endif // DIJKSTRA_H 