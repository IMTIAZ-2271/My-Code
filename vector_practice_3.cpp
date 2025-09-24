#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<pair<char,int>> char_pos;
    for(int i=0; i<s.size(); i++){
        char_pos.push_back({s[i],i});
    }
    sort(char_pos.begin(),char_pos.end());
    
    string ans="";
    auto it=char_pos.begin();
    ans+=it->first;
    int compare = it->second;
    for(auto& p:char_pos){
        if(p.second > compare){

            ans+=p.first;
            compare = p.second;
        }
    }

    cout << ans << endl;
    return 0;
    
}