#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long ans = 0;
    for (int bit = 0; bit < 31; bit++)
    {
        long long cnt1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] & (1 << bit))
                cnt1++;
        }
        long long cnt0 = n - cnt1;
        ans += max(cnt0, cnt1) * (1LL << bit);
    }

    cout << ans << "\n";
    return 0;
}
