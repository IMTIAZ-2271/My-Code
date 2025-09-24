#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string,int> name_st;
    vector<int> rolls;
    int n; cin >> n;
    int k=0;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        if(name_st.find(s) == name_st.end()){
           name_st[s]=k;
           k++;
        }
        else{
            rolls.push_back(name_st[s]);
        }
    }
    for(int p:rolls){cout << p << endl;}

    return 0;
}