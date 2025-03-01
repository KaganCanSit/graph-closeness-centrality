#include <iostream>
#include <iomanip>
#include "Graph.h"
#include "Dijkstra.h"

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
    std::cout << "Graph representation:" << std::endl;
    graph.printGraph();
    
    // Calculate closeness centrality
    Dijkstra dijkstra(graph);
    std::vector<double> centrality = dijkstra.calculateClosenessCentrality();
    
    // Display results
    std::cout << "\nCloseness Centrality for each vertex:" << std::endl;
    std::cout << std::fixed << std::setprecision(6);
    
    for (int i = 0; i < graph.getNumVertices(); i++) {
        std::string label = (i == 0) ? "s" : (i == 7) ? "t" : std::to_string(i);
        std::cout << "Vertex " << label << ": " << centrality[i] << std::endl;
    }
    
    // Find vertex with highest centrality
    int maxCentralityVertex = 0;
    for (int i = 1; i < graph.getNumVertices(); i++) {
        if (centrality[i] > centrality[maxCentralityVertex]) {
            maxCentralityVertex = i;
        }
    }
    
    std::string maxLabel = (maxCentralityVertex == 0) ? "s" : (maxCentralityVertex == 7) ? "t" : std::to_string(maxCentralityVertex);
    std::cout << "\nVertex with highest closeness centrality: " << maxLabel << " (" << centrality[maxCentralityVertex] << ")" << std::endl;
    
    return 0;
} 