#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int given[n][2];
    for (int i = 0; i < n; ++i) {
        cin >> given[i][0] >> given[i][1];
    }
    unordered_map<int, unordered_map<int, bool>> soln;
    int x, k;
    for (int i = 0; i < n; ++i)
    {
        x = given[i][0];
        k = given[i][1];
        soln[k][x] = true;
        if (x != 0)
        {
            if (!soln[k][x-1] )
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;

    return 0;
}