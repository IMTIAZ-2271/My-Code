#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>

using namespace std;

void solve()
{
    int m, k;
    cin >> m >> k;
    vector<int> d(m + 1, 0);
    vector<int> s(m + 1, 0);
    vector<int> local_max(m + 1, 0);

    for (int i = 1; i <= m; ++i)
    {
        cin >> d[i];
    }
    int maxs = 0;
    for (int i = 1; i <= m; ++i)
    {
        cin >> s[i];
        local_max[i] = maxs = max(s[i], maxs);
    }
    int time = 0;
    int curr_fuel = 0;
    for (int i = 1; i <= m; i++)
    {
        curr_fuel += s[i];
        if (curr_fuel < d[i])
        {
            int fuel_round = (d[i] - curr_fuel + local_max[i] - 1) / local_max[i];
            time += fuel_round * k;
            curr_fuel += fuel_round * local_max[i];
        }
        time += d[i];
        curr_fuel-=d[i];
    }
    cout << time << endl;
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