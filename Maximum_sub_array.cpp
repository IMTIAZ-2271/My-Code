#include <bits/stdc++.h>
using namespace std;
#define hurryup                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

typedef long long ll;
int main()
{
    hurryup;
    string s;
    cin >> s;
    int i=0,j=0;
    int maximum_sub = 0;
    for(i=0; i<s.size(); i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            maximum_sub = max(maximum_sub,i - j);
            j=i+1;
        }
    }
    maximum_sub = max(maximum_sub,i - j);
    cout<<maximum_sub << "\n";

    return 0;
}