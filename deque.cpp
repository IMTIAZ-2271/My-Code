#include<bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> assembly;
    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int pos,ID;
            cin >> pos >> ID;
            if(pos == 0){

                assembly.push_front(ID);
            }
            else if (pos == 1){
                assembly.push_back(ID);
            }
        }
        else if (type == 2){
            int pos ; cin >> pos;
            if(pos == 0){
                assembly.pop_front();
            }
            else if(pos == 1){
                assembly.pop_back();
            }
        }
    }
    for (int p:assembly){
        cout << p ;
    }
     return 0;
}