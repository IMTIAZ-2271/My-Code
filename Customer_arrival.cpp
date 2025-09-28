#include<bits/stdc++.h>
using namespace std;
#define hurryup ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
typedef long long int ll;
int main()
{
    hurryup;
    ll n;
    cin >> n;
    vector<pair<ll,ll>> a;
    for(int i = 0 ; i < n ; i++)
    {
        ll arrive,depart;
        cin >> arrive >> depart;
        a.push_back({arrive,1});
        a.push_back({depart,-1});
    }
    sort(a.begin(),a.end());
    ll sz = a.size();
    ll ans = 0;
    ll curr = 0;
    for(int i = 0 ; i < sz ; i++)
    {
        if(i>n-1 && a[i].first == a[i+1].first )
        {
            curr += a[i].second;
            //i++;
        }
        else{
        curr += a[i].second;
        ans = max(ans,curr);
        }
    }
    cout << ans << endl;
    return 0;
}