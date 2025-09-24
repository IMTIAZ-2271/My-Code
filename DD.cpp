#include<bits/stdc++.h>
using namespace std;
#define hurryup ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
typedef long long ll;
int main()
{
    hurryup;
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll sum = 0;
        vector<ll> a(n);
        for(int i = 0; i<n; i++) cin >> a[i], sum+=a[i];
        ll avg = sum/n;
        ll check = 0;
        for(int i = 0; i<n; i++){
            if(check >= 0) check+= (a[i]-avg); // Never go negative
            else {
                break;
            }
        }
        if(check == 0) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}