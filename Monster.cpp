#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int src_i, src_j;

    vector<vector<char>> Map(n + 1, vector<char>(m + 1));
    vector<pair<int, int>> Monster;

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
            else if (Map[i][j] == 'M')
            {
                Monster.push_back({i, j});
            }
        }
    }

    const int INF = 1e9;
    vector<vector<int>> Monster_dist(n + 1, vector<int>(m + 1, INF));

    vector<int> di = {0, 0, 1, -1};
    vector<int> dj = {1, -1, 0, 0};
    vector<char> move = {'R', 'L', 'D', 'U'};

    queue<pair<int, int>> q;

    for (const auto &it : Monster)
    {
        q.push({it.first, it.second});
        Monster_dist[it.first][it.second] = 0;
    }

    while (!q.empty())
    {
        int curr_i = q.front().first;
        int curr_j = q.front().second;
        int curr_dist = Monster_dist[curr_i][curr_j];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nxt_i = curr_i + di[i];
            int nxt_j = curr_j + dj[i];

            if (nxt_i >= 1 && nxt_i <= n && nxt_j >= 1 && nxt_j <= m)
            {
                if (Map[nxt_i][nxt_j] != '#' && Monster_dist[nxt_i][nxt_j] > curr_dist + 1)
                {
                    Monster_dist[nxt_i][nxt_j] = curr_dist + 1;
                    q.push({nxt_i, nxt_j});
                }
            }
        }
    }

    if (src_i == 1 || src_i == n || src_j == 1 || src_j == m)
    {
        cout << "YES\n0\n";
        return;
    }

    // 3. Player BFS
    vector<vector<int>> player_dist(n + 1, vector<int>(m + 1, INF));
    vector<vector<char>> parent_pos(n + 1, vector<char>(m + 1, '!'));

    q.push({src_i, src_j});
    player_dist[src_i][src_j] = 0;

    int exit_i = -1;
    int exit_j = -1;
    bool possible = false;

    while (!q.empty() && !possible)
    {
        int curr_i = q.front().first;
        int curr_j = q.front().second;
        int curr_dist = player_dist[curr_i][curr_j];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nxt_i = curr_i + di[i];
            int nxt_j = curr_j + dj[i];

            if (nxt_i >= 1 && nxt_i <= n && nxt_j >= 1 && nxt_j <= m)
            {
                int nxt_dist = curr_dist + 1;

                if (Map[nxt_i][nxt_j] != '#' && player_dist[nxt_i][nxt_j] == INF && nxt_dist < Monster_dist[nxt_i][nxt_j])
                {
                    player_dist[nxt_i][nxt_j] = nxt_dist;
                    parent_pos[nxt_i][nxt_j] = move[i];
                    q.push({nxt_i, nxt_j});

                    if (nxt_i == 1 || nxt_i == n || nxt_j == 1 || nxt_j == m)
                    {
                        exit_i = nxt_i;
                        exit_j = nxt_j;
                        possible = true;
                        break;
                    }
                }
            }
        }
    }

    if (!possible)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        stack<char> path_desc;
        int i = exit_i;
        int j = exit_j;

        while (!(i == src_i && j == src_j))
        {
            char t = parent_pos[i][j];
            path_desc.push(t);
            if (t == 'R')
            {
                j--;
            }
            else if (t == 'L')
            {
                j++;
            }
            else if (t == 'D')
            {
                i--;
            }
            else if (t == 'U')
            {
                i++;
            }
        }

        cout << path_desc.size() << "\n";
        while (!path_desc.empty())
        {
            cout << path_desc.top();
            path_desc.pop();
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}