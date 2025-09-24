#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<char> open_bracket;
    vector<char> close_bracket;
    string brackets;
    cin >> brackets;
    for(int i=0; i<brackets.size(); i++){
        if(brackets[i]=='('){
          open_bracket.push_back(brackets[i]);
        }
        else if(brackets[i]=')'){
             if(!open_bracket.empty()){
                open_bracket.pop_back();
             }
             else{
                close_bracket.push_back(brackets[i]);
             }
        }
    }
    cout << open_bracket.size() + close_bracket.size() << endl;

    return 0;

}