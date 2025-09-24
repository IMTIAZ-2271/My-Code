#include <bits/stdc++.h>
using namespace std;
#define hurryup                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll sum = 0;
    ll ans = INT_MAX;

    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }
    int i = 0; 
    while (i < n - k)
    {
        sum -= a[i];
        sum += a[i + k];
        ans = min(ans, sum);
        i++;
    } 
    cout << ans << "\n";

    return 0;
}