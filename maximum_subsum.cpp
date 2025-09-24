#include <bits/stdc++.h>
using namespace std;
#define hurryup                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
typedef long long ll;
int main()
{
    hurryup;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int i = 0;
        int j = k - 1;
        int max_sum = 0;
        for (int m = i; m <= j; m++)
            max_sum += a[m];
        for (int x = 0; x < n - k; x++)
        {
            max_sum = fmax(max_sum, max_sum - a[i] + a[j + 1]);
            i++;
            j++;
        }
        cout << max_sum << "\n";
    }
    return 0;
}