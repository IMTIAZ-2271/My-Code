#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{

    int m;
    cin >> m;
    vector<int> q(m);
    for (size_t i = 0; i < m; i++)
    {
        cin >> q[i];
    }
    sort(q.begin(), q.end());
    int n;
    cin >> n;
    vector<long long> price(n, 0);
    vector<long long> prefsum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    sort(price.begin(), price.end(), greater<long long>());
    for (size_t i = 1; i <= n; i++)
    {
        prefsum[i] = price[i - 1] + prefsum[i - 1];
    }
    int taken = q[0];
    long long amount = 0;
    int l = 0;
    for (int i = taken; i <= n; i += taken)
    {
        amount += prefsum[i] - prefsum[i - taken];

        i += (i + 2 > n) ? ((i + 1 > n) ? 0 : 1) : 2;
        l = i;
    }
    amount += prefsum[n] - prefsum[l];

    cout << amount << endl;
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