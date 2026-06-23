#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
#include <algorithm>

using namespace std;
typedef struct info
{
    int freq = 0;
    int l = 0;
    int r = 0;
} info;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    map<int, info> da;
    int maxfreq = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        da[x].freq++;
        maxfreq = max(maxfreq, da[x].freq);
        if (da[x].l == 0)
        {
            da[x].l = i + 1;
        }
        da[x].r = i + 1;
    }
    int ansl, ansr;
    ansl = 1;
    ansr = n;

    for (auto it : da)
    {
        if (maxfreq == it.second.freq)
        {
            if (ansr - ansl + 1 > it.second.r - it.second.l + 1)
            {
                ansl = it.second.l;
                ansr = it.second.r;
            }
        }
    }

    cout << ansl << " " << ansr << endl;

    return 0;
}