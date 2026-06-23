#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
#include <cmath>
#include <limits.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n, 0);
    // set<long long> unique_numbers;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long minr = LLONG_MAX;
    long long r = 0;
    int e = 0;
    for (int i = 0; i < n; i++)
    {
        
        r = 0;
        if (a[i] <= i)
        {
            cout << i + 1 << endl;
            return 0;
        }
        r = (a[i] - i + n -1)/n;
        if (r < minr)
        {
            minr = r;
            e = i + 1;
        }
    }
    cout << e << endl;

    return 0;
}