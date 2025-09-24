#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int query; cin >> query;
    while(query--){
        int type; cin >> type;
        if(type == 1){
            int x; cin >> x;
            a.push_back(x);
        }
        else if(type == 2){
            int pos; cin >> pos;

            a.erase(a.begin()+pos);
        }
        else if(type == 3){
            int i; cin >> i;
            int count = 0;
            for(int p:a){
                if(p>a[i]){count++;}
        
            }
            cout << count << endl;

        }
    }

    return 0;
}