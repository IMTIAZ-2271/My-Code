#include <bits/stdc++.h>
using namespace std;
#define hurryup                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

typedef long long ll;
typedef double d;
int main()
{
    hurryup;

    ll n, k;
    cin >> n;
    vector<ll> input(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    sort(input.begin(), input.end());
    cin >> k;
    while (k--)
    {
        ll l, r;
        cin >> l >> r;
        ll l_index = n, r_index = -1;
        ll left = 0;
        ll right = n - 1;

        while (left <= right)
        {
            ll mid = (left + right) / 2;
            if (input[mid] >= l)
            {
                l_index = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        ll left = 0;
        ll right = n - 1;

        while (left <= right)
        {
            ll mid = (left + right) / 2;
            if (input[mid] > r)
            {
                right = mid - 1;
            }
            else
            {
                r_index = mid;
                left = mid + 1;
            }
        }

        ll ans = 0;
        if (l_index <= r_index)
            ans = r_index - l_index + 1;

        cout << ans << "\n";
    }

    return 0;
}