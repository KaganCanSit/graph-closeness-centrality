#include "Graph.h"

Graph::Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

void Graph::addEdge(int src, int dest, int weight) {
    adjList[src].emplace_back(dest, weight);
}

void Graph::printGraph() const {
    for (int i = 0; i < numVertices; i++) {
        std::cout << "Adjacency list of vertex " << i << ": ";
        for(const auto& edge : adjList[i]) {
            std::cout << " -> (" << edge.destination << "," << edge.weight << ") ";
        }
        std::cout << std::endl;
    }
} 