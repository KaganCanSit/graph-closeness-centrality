#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <queue>
#include <limits>

#include "Graph.hpp"

class Dijkstra {
public:
    [[nodiscard]] static std::vector<size_t> shortestPath(size_t start, const Graph& graph) noexcept;
};

#endif // DIJKSTRA_H 