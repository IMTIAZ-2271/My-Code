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
    while (tcs--)
    {
        int n;
        cin >> n;
        int length = 0;
        vector<int> arr(101, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr[x]++;
        }
        sort(arr.begin(), arr.end(), greater<int>());
        for(int i = 0; i<n; i++)
        {
            length = max(length, (i+1)*arr[i]);
        }
        
        cout << length << "\n";
    }

    return 0;
}