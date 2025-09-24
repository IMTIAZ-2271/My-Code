#include <bits/stdc++.h>
using namespace std;
#define ios_base              \
    ::sync_with_stdio(false); \
    cin.tie(nullptr);         \
    cout.tie(nullptr)
#define ll long long
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    ll count = 0;

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i < k && a[i] < 0)
        {
            count++;
        }
    }
    ll i = 0;
    ll j = k;
    cout << count << "\n";
    while (j < n)
    {
        if (a[i] < 0)
        {
            count--;
        }
        if (a[j] < 0)
        {
            count++;
        }
        cout << count << "\n";
        i++;
        j++;
    }
    return 0;
}
