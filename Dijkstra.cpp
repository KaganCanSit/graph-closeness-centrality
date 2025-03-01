#include "Dijkstra.hpp"

std::vector<int> Dijkstra::shortestPath(int start, const Graph& graph) {
    int V = graph.getNumVertices();
    std::vector<int> dist(V, std::numeric_limits<int>::max());
    dist[start] = 0;

    using Pair = std::pair<int, int>;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    pq.emplace(0, start);
    
    while (!pq.empty()) {
        auto [currentDist, u] = pq.top();
        pq.pop();

        if (currentDist > dist[u]) continue; // Skip if already processed
        
        for (const auto& edge : graph.getAdjList(u)) {
            int v = edge.destination;
            int weight = edge.weight;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}