#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <iostream>

// Node in adjacency list
struct Edge {
    int destination;
    int weight;
    Edge* next;
    
    Edge(int dest, int w) : destination(dest), weight(w), next(nullptr) {}
};

// Graph represented as adjacency list
class Graph {
private:
    int numVertices;
    Edge** adjList;  // Array of linked lists
    
public:
    Graph(int vertices);
    ~Graph();
    
    void addEdge(int src, int dest, int weight);
    void printGraph() const;
    int getNumVertices() const { return numVertices; }
    Edge* getAdjList(int vertex) const { return adjList[vertex]; }
};

#endif // GRAPH_H 