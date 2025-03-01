#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <sstream>

// Node in adjacency list
struct Edge {
    int destination;
    int weight;
    
    Edge(int dest, int w) : destination(dest), weight(w){}
};

// Graph represented as adjacency list
class Graph {
private:
    int numVertices;
    std::vector<std::vector<Edge>> adjList; // Array of linked lists
    
public:
    explicit Graph(int vertices);
    
    void addEdge(int src, int dest, int weight);
    const std::string getGraphAsString() const;

    int getNumVertices() const { return numVertices; }
    const std::vector<Edge>& getAdjList(int vertex) const { return adjList[vertex]; }
};

#endif // GRAPH_H 