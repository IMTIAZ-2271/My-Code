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

    ll n , k;
    cin >> n >> k;

    vector<ll> input(n);
    for(ll i = 0; i<n; i++)
    {
        cin >> input[i];
    }
    while(k--)
    {
        ll x;
        cin >> x;
        ll index = 0;
        ll left = 0;
        ll right = n-1;
        //ll ans = 0;
        ll mid ;
        while(left <= right)
        {
            mid = (left + right)/2;
            if(input[mid]<=x)
            {
               //ans  = mid;
               index = mid + 1;
               left = mid + 1;
            }
            else 
            {
                right = mid - 1;
            }
        }
        cout << index << endl;
    }



return 0;  
}