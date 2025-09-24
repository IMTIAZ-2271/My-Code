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
    ll N, M;
    cin >> N >> M;
    vector<ll> production_per_second(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> production_per_second[i];
    }
    ll left = 1;
    ll right = 1e18;
    ll sum = 0;
    ll ans = 0;
    while (left <= right)
    {
        ll mid = (long long )(left + right) / 2;
        for (ll j = 0; j < N; j++)
        {
            sum += mid / production_per_second[j];
        }
        if (sum >= M)
        {
            ans= mid;
            right = mid - 1LL;
        }
        else
        {
            left = mid + 1LL ;
        }
        sum = 0;
    }
    cout << ans << endl;

    return 0;
}