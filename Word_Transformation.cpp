#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

void solve()
{

    int n;
    cin >> n;
    unordered_set<string> words_set;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        words_set.insert(str);
    }
    string start, end;
    cin >> start >> end;
    if (start == end)
    {
        cout << 0 << endl;
        return;
    }
    queue<pair<string, int>> Q;
    Q.push({start, 0});

    if (words_set.find(start) != words_set.end()) {
        words_set.erase(start);
    }

    while (!Q.empty())
    {
        string currword = Q.front().first;
        int steps = Q.front().second;

        Q.pop();

        if (currword == end)
        {
            cout << steps << endl;
            return;
        }

        for (int i = 0; i < currword.length(); i++)
        {

            char t = currword[i];

            for (int j = 0; j < 26; j++)
            {
                if ((char)('a' + j) == currword[i])
                {
                    continue;
                }

                currword[i] = 'a' + j;

                if (words_set.find(currword) != words_set.end())
                {
                    Q.push({currword, steps + 1});
                    words_set.erase(currword);
                }
            }
            currword[i] = t;
        }
    }


    cout << -1 << endl;
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