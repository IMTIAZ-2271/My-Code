#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    if (k > n)
        k = n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }
    if (k == n)
    {
        cout << s[n - 1] << endl;
    }
    else
    {
        int size = INT_MIN;
        int l = 0;
        int r = (n == 2 * k) ? n - 1 : (2 * (n % k) - 1);
        int extra = r + 1;
        while (l < r)
        {
            size = max(size, s[l++] + s[r--]);
        }
        for (int i = extra; i < n; ++i)
        {
            size = max(size, s[i]);
        }
        cout << size << endl;
    }

    return 0;
}