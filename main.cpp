#include <iostream>
#include <iomanip>

#include "Graph.hpp"
#include "Dijkstra.hpp"

void calculateClosenessCentrality(const Graph& graph) {
    size_t V = graph.getNumVertices();
    std::vector<double> centrality(V, 0.0);
    
    for (size_t i = 0; i < V; i++) {
        std::vector<size_t> distances = Dijkstra::shortestPath(i, graph);

        double sumDistances = 0.0;
        int reachableNodes = 0;
        
        for (size_t j = 0; j < V; j++) {
            if (i != j && distances[j] != std::numeric_limits<size_t>::max()) {
                sumDistances += static_cast<double>(distances[j]);
                reachableNodes++;
            }
        }
        
        if (reachableNodes > 0) {
            centrality[i] = static_cast<double>(reachableNodes) / sumDistances;
        }
    }
    
    std::ostringstream os;
    os << "\nCloseness Centrality for each vertex:\n";
    double maxCentrality = 0.0;
    size_t bestVertex = 0;

    for (size_t i = 0; i < V; i++) {
        os << "Vertex " << i << ": " << std::fixed << std::setprecision(6) << centrality[i] << '\n';
        if (centrality[i] > maxCentrality) {
            maxCentrality = centrality[i];
            bestVertex = i;
        }
    }

    os << "\nVertex with highest closeness centrality: " << bestVertex << " (" << maxCentrality << ")\n";
    std::cout << os.str() << std::endl;
} 

int main() {
    // Create a graph based on the image provided
    // s=0, 1=1, 2=2, 3=3, 4=4, 5=5, 6=6, t=7
    Graph graph(8);
    
    // Add edges according to the diagram
    graph.addEdge(0, 1, 2);  // s -> 1
    graph.addEdge(0, 2, 1);  // s -> 2
    graph.addEdge(0, 3, 2);  // s -> 3
    
    graph.addEdge(1, 4, 4);  // 1 -> 4
    graph.addEdge(1, 2, 1);  // 1 -> 2
    
    graph.addEdge(2, 5, 2);  // 2 -> 5
    graph.addEdge(2, 3, 1);  // 2 -> 3
    
    graph.addEdge(3, 6, 2);  // 3 -> 6
    
    graph.addEdge(4, 7, 1);  // 4 -> t
    graph.addEdge(4, 5, 4);  // 4 -> 5
    
    graph.addEdge(5, 7, 5);  // 5 -> t
    graph.addEdge(5, 6, 4);  // 5 -> 6
    
    graph.addEdge(6, 7, 3);  // 6 -> t
    
    // Print the graph representation
    std::cout << "Graph representation:\n" << graph.getGraphAsString() << std::endl;
    calculateClosenessCentrality(graph);
    return 0;
} 