#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<long long int,int> frequency;
    int n;
    cin >> n;
    long long int maxvalue=0;
    for (int i = 0; i < n; i++)
    {
        long long int x;
        cin >> x;
        frequency[x]++;
        maxvalue=fmax(maxvalue,x);
    }
    
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            long long int e;
            cin >> e;
            frequency[e]++;
            maxvalue=fmax(maxvalue,e);
        }
        else if (type == 2)
        {
           long long  int L, R;
            cin >> L >> R;
            vector<long long int> total_count(maxvalue+1, 0LL);
            for (long long int j = 1; j <= R; j++)
            {
                total_count[j] = total_count[j - 1] + frequency[j];
            }
            cout << total_count[R] - total_count[L - 1] << " ";
        }
    }
    

    return 0;
}