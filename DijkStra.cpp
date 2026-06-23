#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Pair representing {weight, vertex}
typedef pair<int, int> iPair; 

void dijkstra(int V, vector<vector<iPair>>& adj, int source) {
    // Priority queue to store {distance, vertex}. Min-heap.
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    
    // Initialize distances to infinity
    vector<int> dist(V, INT_MAX);

    // Insert source into priority queue and initialize its distance to 0
    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty()) {
        // The greedy choice: Extract the vertex with the minimum distance
        int u = pq.top().second;
        pq.pop();

        // Traverse all adjacent vertices of u
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; ++i)
        cout << i << " \t\t " << dist[i] << endl;
}

int main() {
    int V = 5;
    vector<vector<iPair>> adj(V);
    
    // Adding edges: u, v, weight
    adj[0].push_back({1, 10});
    adj[0].push_back({4, 5});
    adj[1].push_back({2, 1});
    adj[4].push_back({1, 3});
    adj[4].push_back({2, 9});
    adj[4].push_back({3, 2});
    adj[2].push_back({3, 4});

    dijkstra(V, adj, 0);
    return 0;
}