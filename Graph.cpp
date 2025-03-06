#include "Graph.hpp"

Graph::Graph(size_t vertices) noexcept : adjList(vertices) {}

void Graph::addEdge(size_t src, size_t dest, size_t weight) {
    adjList[src].emplace_back(dest, weight);
}

std::string Graph::getGraphAsString() const noexcept {
    std::ostringstream os;
    for (size_t i = 0; i < adjList.size(); i++) {
        os << "Adjacency list of vertex " << i << ": ";
        for(const auto& edge : adjList[i]) {
            os << " -> (" << edge.destination << "," << edge.weight << ") ";
        }
        os << '\n';
    }
    return os.str();
} 