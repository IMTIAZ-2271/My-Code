#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), px(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        px[i] = a[i] ^ (i ? px[i - 1] : 0);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int result = px[r - 1] ^ (l > 1 ? px[l - 2] : 0);
        cout << result << "\n";
    }

    return 0;
}
