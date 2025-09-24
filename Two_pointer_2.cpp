#include<bits/stdc++.h>
using namespace std;
#define hurryup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    ll target ;
    cin >> target;
    vector<pair<ll,int>> a(n);
    for(int i=0 ; i<n; i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(),a.end());
    int i=0, j=n-1;
    while(i<j){
        ll sum = a[i].first + a[j].first;
        if(sum == target){
            cout << a[i].second << " " << a[j].second << "\n";
            i++;
            j--;
        }
        else if(sum < target){
            i++;
        }
        else{
            j--;
        }
    }


}