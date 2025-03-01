#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>

class Dijkstra {
public:
    static std::vector<int> shortestPath(int start, const Graph& graph);
};

#endif // DIJKSTRA_H 