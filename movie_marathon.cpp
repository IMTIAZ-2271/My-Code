#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long int totaltime = 0;
    vector<long long int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        totaltime += a[i];
    }

    sort(a.begin(), a.end());

    long long int extra = 0LL;
    // long long int min = 0LL;

    if (a[n - 1] > totaltime - a[n - 1])
    {
        extra = abs(2 * a[n - 1] - totaltime);
    }

    cout << totaltime + extra << endl;

    return 0;
}