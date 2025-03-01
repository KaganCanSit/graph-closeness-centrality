#include "Dijkstra.h"

std::vector<int> Dijkstra::shortestPath(int start, std::vector<int>& lambda, std::vector<int>& P) {
    int n = graph.getNumVertices();
    
    // Initialize lambda (distances) with infinity
    lambda.assign(n, std::numeric_limits<int>::max());
    lambda[start] = 0;
    
    // Initialize parent vector P
    P.assign(n, -1);
    
    // Initialize T (vertices to be visited)
    std::vector<bool> T(n, true);
    
    // Min priority queue for selecting next vertex
    // Pair: (distance, vertex)
    std::priority_queue<std::pair<int, int>, 
                         std::vector<std::pair<int, int>>, 
                         std::greater<std::pair<int, int>>> pq;
    
    // Start with the source vertex
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (!T[u]) continue; // Skip if already processed
        
        T[u] = false; // Mark as processed
        
        // Iterate through all adjacent vertices
        Edge* edge = graph.getAdjList(u);
        while (edge) {
            int v = edge->destination;
            int weight = edge->weight;
            
            // Relaxation step
            if (T[v] && lambda[u] != std::numeric_limits<int>::max() && 
                lambda[u] + weight < lambda[v]) {
                lambda[v] = lambda[u] + weight;
                P[v] = u;
                pq.push({lambda[v], v});
            }
            
            edge = edge->next;
        }
    }
    
    return lambda;
}

std::vector<double> Dijkstra::calculateClosenessCentrality() {
    int n = graph.getNumVertices();
    std::vector<double> centrality(n, 0.0);
    
    for (int i = 0; i < n; i++) {
        std::vector<int> lambda;
        std::vector<int> P;
        
        // Get shortest paths from vertex i to all others
        std::vector<int> distances = shortestPath(i, lambda, P);
        
        // Calculate sum of shortest paths
        double sum = 0.0;
        int reachableVertices = 0;
        
        for (int j = 0; j < n; j++) {
            if (i != j && distances[j] != std::numeric_limits<int>::max()) {
                sum += distances[j];
                reachableVertices++;
            }
        }
        
        // Calculate closeness centrality
        // Avoid division by zero
        if (reachableVertices > 0) {
            centrality[i] = reachableVertices / sum;
        } else {
            centrality[i] = 0.0;
        }
    }
    
    return centrality;
} 