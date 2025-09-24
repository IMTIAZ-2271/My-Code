#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; 
    cin >> n;
    if(n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    vector<int> arr(n);
    map<long long ,int> mp;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    int cnt=0;
    for(auto it : mp)
    {
        if(it.second == 1)
        {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;


}