#include "Graph.hpp"

Graph::Graph(size_t vertices) : numVertices(vertices), adjList(vertices) {}

void Graph::addEdge(size_t src, size_t dest, size_t weight) {
    adjList[src].emplace_back(dest, weight);
}

const std::string Graph::getGraphAsString() const {
    std::ostringstream os;
    for (size_t i = 0; i < numVertices; i++) {
        os << "Adjacency list of vertex " << i << ": ";
        for(const auto& edge : adjList[i]) {
            os << " -> (" << edge.destination << "," << edge.weight << ") ";
        }
        os << '\n';
    }
    return os.str();
} 