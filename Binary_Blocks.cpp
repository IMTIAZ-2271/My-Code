#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    int max_dim = max(m, n);
    int MAX_SIZE = 2 * max_dim + 5;

    vector<vector<int>> pref_ct_1(MAX_SIZE, vector<int>(MAX_SIZE, 0));

    for (int i = 1; i <= m; ++i)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= n; ++j)
        {
            pref_ct_1[i][j] = str[j - 1] - '0';
        }
    }

    for (int i = 1; i < MAX_SIZE; ++i)
    {
        for (int j = 1; j < MAX_SIZE; ++j)
        {
            pref_ct_1[i][j] = pref_ct_1[i][j] + pref_ct_1[i - 1][j] + pref_ct_1[i][j - 1] - pref_ct_1[i - 1][j - 1];
        }
    }

    int min_flip = INT_MAX;

    for (int k = 2; k <= max_dim; ++k)
    {
        int count = 0;
        for (int i = 1; i <= m; i += k)
        {
            for (int j = 1; j <= n; j += k)
            {
                int ones = pref_ct_1[i + k - 1][j + k - 1] - pref_ct_1[i - 1][j + k - 1] - pref_ct_1[i + k - 1][j - 1] + pref_ct_1[i - 1][j - 1];
                int zeros = (k * k) - ones;
                count += min(ones, zeros);
            }
        }

        if (count < min_flip)
        {
            min_flip = count;
        }
    }

    cout << min_flip << endl;
    return 0;
}