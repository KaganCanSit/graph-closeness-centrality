#include "Dijkstra.hpp"

std::vector<size_t> Dijkstra::shortestPath(size_t start, const Graph& graph) {
    size_t V = graph.getNumVertices();
    std::vector<size_t> dist(V, std::numeric_limits<size_t>::max());
    dist[start] = 0;

    using Pair = std::pair<size_t, size_t>;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    pq.emplace(0, start);
    
    while (!pq.empty()) {
        auto [currentDist, u] = pq.top();
        pq.pop();

        if (currentDist > dist[u]) continue; // Skip if already processed
        
        for (const auto& edge : graph.getAdjList(u)) {
            size_t v = edge.destination;
            size_t weight = edge.weight;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}