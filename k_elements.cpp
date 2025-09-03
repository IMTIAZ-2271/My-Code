#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> qui;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        qui.push(a);
    }
    int k;
    cin >> k;
    stack<int> temp;

    for(int i=0; i<k; i++){
        temp.push(qui.front());
        qui.pop();
    }
    queue<int > quo;
    for(int i=0; i<k; i++){
        quo.push(temp.top());
        temp.pop();
    }
    while(!qui.empty()){
        quo.push(qui.front());
        qui.pop();
    }
    for(int i=0; i<n; i++){
        int t = quo.front();
        cout << t << " " ;
        quo.pop();
    }
    cout << endl;

    return 0;

}