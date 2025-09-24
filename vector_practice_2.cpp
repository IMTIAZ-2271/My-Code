#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int pos = max_element(v.begin(), v.end()) - v.begin();
            v[pos] = v[pos]>>1;
        }
        else if (a == 2)
        {
            int pos = min_element(v.begin(), v.end()) - v.begin();
            v[pos] =  v[pos]<<1;
        }
    }
    int sum = 0;
    for (int p : v)
    {
        sum += p;
    }
    cout << sum << endl;

    return 0;
}