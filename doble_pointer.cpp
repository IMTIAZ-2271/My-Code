#include <bits/stdc++.h>
using namespace std;
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    
    long long int n, m, k;
    cin >> n >> m >> k;

    vector<long long> customer(n);

    for (int i = 0; i < n; i++)
        cin >> customer[i];

    sort(customer.begin(), customer.end());

    vector<long long> shop(m);

    for (int i = 0; i < m; i++)
        cin >> shop[i];

    sort(shop.begin(), shop.end());

    int c = n - 1, s = m - 1, cnt = 0;
    while (c >= 0 && s >= 0)
    {
        if (abs(customer[c] - shop[s]) <= k)
        {
            cnt++;
            c--;
            s--;
        }
        else
        {
            if (customer[c] > shop[s])
            {
                c--;
            }
            else
            {
                s--;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}