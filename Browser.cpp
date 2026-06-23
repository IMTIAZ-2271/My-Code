#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, pos, l, r;
    cin >> n >> pos >> l >> r;
    int ans = 0;
    if (r - l + 1 != n)
    {
        if (l == 1)
        {
            ans = abs(r - pos) + 1;
        }
        else if (r == n)
        {
            ans = abs(pos - l) + 1;
        }
        else
        {
            ans = min(abs(pos - l), abs(r - pos)) + (r - l) + 2;
        }
    }
    cout << ans << endl;
    return 0;
}