#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <chrono> // Added for time measurement

using namespace std;
using namespace std::chrono; // Added for easy time measurement syntax

// 1. Queue Approach (Notice in_degree is passed BY VALUE without the '&' so it makes a copy)
void Kahns_topological_sort(int n, const vector<vector<int>> &adj_list, vector<int> in_degree)
{
    vector<int> order;
    queue<int> Q;
    
    for (int u = 1; u <= n; ++u)
    {
        if (in_degree[u] == 0)
        {
            Q.push(u);
        }
    }
    
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        order.push_back(u);
        for (int v : adj_list[u])
        {
            in_degree[v]--;
            if (in_degree[v] == 0)
            {
                Q.push(v);
            }
        }
    }

    if (order.size() != n) cout << "Queue: Not a DAG." << endl;
    // Muted printing the actual order for benchmarking
}

// 2. Multiset Approach (Wrapped in a function, in_degree passed BY VALUE)
void Multiset_topological_sort(int n, const vector<vector<int>> &adj_list, vector<int> in_degree)
{
    multiset<pair<int, int>> ms;
    for (int i = 1; i <= n; i++)
    {
        ms.insert({in_degree[i], i});
    }
    
    vector<bool> taken(n + 1, false);
    vector<int> order;
    
    while (!ms.empty())
    {
        auto it = *ms.begin();
        ms.erase(ms.begin());
        
        if (it.first > 0)
        {
            break;
        }
        
        int u = it.second;
        if (taken[u]) continue;
        taken[u] = true;
        order.push_back(u);
        
        for (int v : adj_list[u])
        {
            in_degree[v]--;
            ms.insert({in_degree[v], v});
        }
    }

    if (order.size() != n) cout << "Multiset: Not a DAG." << endl;
    // Muted printing the actual order for benchmarking
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0; // Safe read
    
    vector<vector<int>> adj_list(n + 1);
    vector<int> in_degree(n + 1, 0);
    
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        in_degree[v]++;
    }

    // --- BENCHMARK 1: QUEUE ---
    auto start_q = high_resolution_clock::now(); // Start timer
    Kahns_topological_sort(n, adj_list, in_degree);
    auto end_q = high_resolution_clock::now();   // Stop timer
    
    auto duration_q = duration_cast<milliseconds>(end_q - start_q);
    cout << "Queue time:    " << duration_q.count() << " ms" << "\n";

    // --- BENCHMARK 2: MULTISET ---
    auto start_ms = high_resolution_clock::now(); // Start timer
    Multiset_topological_sort(n, adj_list, in_degree);
    auto end_ms = high_resolution_clock::now();   // Stop timer
    
    auto duration_ms = duration_cast<milliseconds>(end_ms - start_ms);
    cout << "Multiset time: " << duration_ms.count() << " ms" << "\n";

    return 0;
}