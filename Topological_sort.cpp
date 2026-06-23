#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
void Kahns_topological_sort(int n, vector<vector<int>> &adj_list, vector<int> in_degree)
{
    cout << "Kahn's topological sort: ";
    // vector<int> in_degree(n + 1, 0);
    vector<int> order;
    queue<int> Q;
    // for (int u = 1; u <= n; ++u)
    // {
    //     for (int v : adj_list[u])
    //     {
    //         in_degree[v]++;
    //     }
    // }
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

    if (order.size() != n)
    {
        cout << "This is not a DAG.Topological sort is not possible." << endl;
    }
    else
    {
        // for (int x : order)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
         cout << "Sorted order: Kahs's " << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj_list(n + 1);
    vector<int> in_degree(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        in_degree[v]++;
    }
    Kahns_topological_sort(n, adj_list, in_degree);
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
        if (taken[u])
            continue;
        taken[u] = true;
        order.push_back(u);
        for (int v : adj_list[u])
        {
            in_degree[v]--;
            ms.insert({in_degree[v], v});
        }
    }
    cout << "Topological sort(multiset): ";

    if (order.size() != n)
    {
        cout << "This is not a DAG.Topological sort is not possible." << endl;
    }
    else
    {
        cout << "Sorted order: multiset";
        // for (int x : order)
        // {
        //     cout << x << " ";
        // }
        cout << endl;
    }
    return 0;
}
