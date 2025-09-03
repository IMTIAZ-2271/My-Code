#include<bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    cin >> input;
    stack<char> check;

    bool flag=true;
    for(char c:input){
       if(c=='(' || c== '{' || c == '['){
        check.push(c);
       }
       else if(c==')' || c== '}' || c == ']'){
        char comp = check.top();
        check.pop();
        if(comp=='('&&c!=')' || comp=='{'&&c!='}' || comp=='['&&c!=']' ){
            cout << "Imbalanced" << endl;
            break;
        }
       }
    }



    return 0;
}