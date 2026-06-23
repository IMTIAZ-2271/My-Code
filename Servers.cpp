#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> servers(n + 1, 0);
    int ti, ki, di;
    for (int i = 1; i <= q; ++i)
    {
        cin >> ti >> ki >> di;
        int count = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (servers[i] < ti)
                count++;
        }
        if (count >= ki)
        {
            int sum = 0;
            for (int i = 1; i <= n && ki > 0; ++i)
            {
                if (servers[i] < ti)
                {
                    ki--;
                    servers[i] = ti + di - 1;
                    sum += i;
                }
            }
            cout << sum << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}