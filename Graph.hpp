#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <sstream>

// Node in adjacency list
struct Edge {
    const size_t destination;
    const size_t weight;
    
    Edge(size_t dest, size_t w) : destination(dest), weight(w){}
};

// Graph represented as adjacency list
class Graph {
private:
    std::vector<std::vector<Edge>> adjList; // Array of linked lists
    
public:
    explicit Graph(size_t vertices);
    
    void addEdge(size_t src, size_t dest, size_t weight);
    const std::string getGraphAsString() const;

    size_t getNumVertices() const { return adjList.size(); }
    const std::vector<Edge>& getAdjList(size_t vertex) const { return adjList[vertex]; }
};

#endif // GRAPH_H 