#include <iostream>
#include <iomanip>
#include "Graph.h"
#include "Dijkstra.h"


void calculateClosenessCentrality(const Graph& graph) {
    int V = graph.getNumVertices();
    std::vector<double> centrality(V, 0.0);
    
    for (int i = 0; i < V; i++) {
        std::vector<int> distances = Dijkstra::shortestPath(i, graph);

        double sumDistances = 0.0;
        int reachableNodes = 0;
        
        for (int j = 0; j < V; j++) {
            if (i != j && distances[j] != std::numeric_limits<int>::max()) {
                sumDistances += distances[j];
                reachableNodes++;
            }
        }
        
        if (reachableNodes > 0) {
            centrality[i] = static_cast<double>(reachableNodes) / sumDistances;
        }
    }
    
    std::cout << "\nCloseness Centrality for each vertex:\n";
    double maxCentrality = 0.0;
    int bestVertex = -1;

    for (int i = 0; i < V; i++) {
        std::cout << "Vertex " << i << ": " << std::fixed << std::setprecision(6) << centrality[i] << '\n';
        if (centrality[i] > maxCentrality) {
            maxCentrality = centrality[i];
            bestVertex = i;
        }
    }

    std::cout << "\nVertex with highest closeness centrality: " << bestVertex << " (" << maxCentrality << ")" << std::endl;
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
    std::cout << "Graph representation:" << std::endl;
    graph.printGraph();
    
    calculateClosenessCentrality(graph);
    return 0;
} 