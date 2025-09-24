#include <bits/stdc++.h>
using namespace std;
#define hurryup                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

typedef long long ll;
typedef double d;
int main()
{
    hurryup;
    int tcs;
    cin >> tcs;
    while(tcs--)
    {
        int n , m; cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m, 0));
        set<int> check;
        for(int i = 0; i<n; i++)
        {
            int k;
            cin >> k;
            for(int j = 0; j<k; j++)
            {
                cin >> arr[i][j];
                if(check.size()<m)
                check.insert(arr[i][j]);
            }
        }
        

    }

    return 0;
}