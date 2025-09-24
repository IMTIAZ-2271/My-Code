#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> numbers(n);
    map<int , int> mp;

    for(int i=0; i<n; i++) cin >> numbers[i];

    for(int i=0; i<n; i++){
        if(x-numbers[i]>0 && mp[x-numbers[i]]>0){
            cout<<mp[x-numbers[i]] << " " << i+1 << endl;
            return 0;
        }
        mp[numbers[i]]=i+1;
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}