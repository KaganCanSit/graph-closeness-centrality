#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <sstream>

// Node in adjacency list
struct Edge {
    size_t destination;
    size_t weight;
    
	// Constructor with member initializer list
    constexpr Edge(size_t dest, size_t w) noexcept : destination(dest), weight(w){}

	// Move constructor for better performance
	constexpr Edge(Edge&& other) noexcept : destination(other.destination), weight(other.weight) {}
};

// Graph represented as adjacency list
class Graph {
private:
    std::vector<std::vector<Edge>> adjList; // Array of linked lists
    
public:
    explicit Graph(size_t vertices) noexcept;
    void addEdge(size_t src, size_t dest, size_t weight);
    [[nodiscard]] std::string getGraphAsString() const noexcept;
    [[nodiscard]] constexpr size_t getNumVertices() const noexcept { return adjList.size(); }
    [[nodiscard]] const std::vector<Edge>& getAdjList(size_t vertex) const noexcept { return adjList[vertex]; }
};

#endif // GRAPH_H 