#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, s;
    cin >> n >> s;
    vector<long long int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long int steps = 0;
    if (a[n / 2] < s)
    {
        for (int i = n / 2; i < n; i++)
        {
            if (a[i] < s)
            {
                steps += s - a[i];
            }
        }
    }
    else
    {
        for (int i = 0; i <= n / 2; i++)
        {
            if (a[i] > s)
            {
                steps += a[i] - s;
            }
        }
    }

    cout << steps << endl;
    return 0;
}