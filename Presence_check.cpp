#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int q;
    cin >> q;
    while (q--)
    {
        long long x;
        cin >> x;
        int st = 0, end = n - 1;

        while (st <= end)
        {
            int mid = (st + end) / 2;
            if (arr[mid] == x)
            {
                cout << "YES" << endl;
                break;
            }
            else if (arr[mid] < x)
                st = mid + 1;
            else
                end = mid - 1;
        }
        if (st > end)
            cout << "NO" << endl;
    }

    return 0;
}