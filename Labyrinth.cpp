#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
 
using namespace std;
 
void solve()
{
 
    int n, m;
    cin >> n >> m;
    int src_i, src_j;
    int dest_i, dest_j;
    vector<vector<char>> Map(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> Map[i][j];
            if (Map[i][j] == 'A')
            {
                src_i = i;
                src_j = j;
            }
            else if (Map[i][j] == 'B')
            {
                dest_i = i;
                dest_j = j;
            }
        }
    }
    vector<vector<char>> parent(n + 1, vector<char>(m + 1, '!'));
    parent[src_i][src_j] = 's';
 
    vector<int> di = {0, 0, 1, -1};
    vector<int> dj = {1, -1, 0, 0};
    vector<char> move = {'R', 'L', 'D', 'U'};
    // R L D U
 
    queue<pair<int, int>> q;
 
    q.push({src_i, src_j});
    while (!q.empty())
    {
        int curr_i = q.front().first;
        int curr_j = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nxt_i = curr_i + di[i];
            int nxt_j = curr_j + dj[i];
            if (nxt_i >= 1 && nxt_i <= n && nxt_j >= 1 && nxt_j <= m)
            {
                if (Map[nxt_i][nxt_j] != '#' && parent[nxt_i][nxt_j] == '!')
                {
                    q.push({nxt_i, nxt_j});
                    parent[nxt_i][nxt_j] = move[i];
                }
            }
        }
    }
    if (parent[dest_i][dest_j] == '!')
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        int i = dest_i;
        int j = dest_j;
        stack<char> path_desc;
        while (parent[i][j] != 's')
        {
            path_desc.push(parent[i][j]);
            char t = parent[i][j];
            // R L D U
            if (t == 'R')
            {
                i += di[1];
                j += dj[1];
            }
            else if (t == 'L')
            {
                i += di[0];
                j += dj[0];
            }
            else if (t == 'D')
            {
                i += di[3];
                j += dj[3];
            }
            else if (t == 'U')
            {
                i += di[2];
                j += dj[2];
            }
        }
        cout << path_desc.size() << endl;
        while (!path_desc.empty())
        {
            cout << path_desc.top();
            path_desc.pop();
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}