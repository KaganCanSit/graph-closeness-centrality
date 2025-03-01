#include "Graph.hpp"

Graph::Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

void Graph::addEdge(int src, int dest, int weight) {
    adjList[src].emplace_back(dest, weight);
}

const std::string Graph::getGraphAsString() const {
    std::ostringstream os;
    for (int i = 0; i < numVertices; i++) {
        os << "Adjacency list of vertex " << i << ": ";
        for(const auto& edge : adjList[i]) {
            os << " -> (" << edge.destination << "," << edge.weight << ") ";
        }
        os << '\n';
    }
    return os.str();
} 