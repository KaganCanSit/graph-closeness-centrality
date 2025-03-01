#include "Graph.h"

Graph::Graph(int vertices) {
    this->numVertices = vertices;
    adjList = new Edge*[vertices];
    
    // Initialize all heads to nullptr
    for (int i = 0; i < vertices; i++) {
        adjList[i] = nullptr;
    }
}

Graph::~Graph() {
    // Free all nodes in adjacency lists
    for (int i = 0; i < numVertices; i++) {
        Edge* current = adjList[i];
        while (current) {
            Edge* next = current->next;
            delete current;
            current = next;
        }
    }
    
    // Free the array
    delete[] adjList;
}

void Graph::addEdge(int src, int dest, int weight) {
    // Add edge from src to dest
    Edge* newEdge = new Edge(dest, weight);
    newEdge->next = adjList[src];
    adjList[src] = newEdge;
}

void Graph::printGraph() const {
    for (int i = 0; i < numVertices; i++) {
        std::cout << "Adjacency list of vertex " << i << ": ";
        Edge* current = adjList[i];
        while (current) {
            std::cout << "(" << current->destination << ", " << current->weight << ") ";
            current = current->next;
        }
        std::cout << std::endl;
    }
} 