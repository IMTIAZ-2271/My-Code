// Greedy = Present optimal solution at each step. Don't think about future steps.
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
        int n; cin >> n;
        map<ll, ll> frequency;
        for(int i = 0; i<(n*(n-1))/2; i++){
            ll k; cin >> k;
            //b.insert(k);
            frequency[k]++;
        }
        vector<ll> ans;
        int t= n;
        for(auto i: frequency){
            while(i.second>0 && t>1){
                ans.push_back(i.first);
                i.second-= (t-1);
                t--;
            }
        }
        ll last = frequency.rbegin()->first;
        ans.push_back(last);
        for(auto i: ans) cout << i << " ";
        cout << "\n";
    }
}