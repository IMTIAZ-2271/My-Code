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
    ll n, x , y;
    cin >> n >> x >> y;
    ll m = min(x,y);
    ll k= n-1;
    ll left = 0;
    ll right = 2*1e9;
    ll ans = 0;
    while(left <= right)
    {
        ll mid = (left + right)/2;
        if(mid/x + mid/y >= k)
        {
            ans = mid;
            right = mid -1;
        }
        else 
        {
            left = mid + 1;
        }
    }
    cout << ans+m << endl;

return 0;  
}