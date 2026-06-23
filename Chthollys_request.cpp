#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
1->11          13->1331
2->22
3->33
4->44
5->55
6->66
7->77
8->88
9->99
10->1001
11->1111
12->1221
*/
int main()
{
    long long k, p;
    cin >> k >> p;
    long long ans = 0;
    for (long long i = 1; i <= k; ++i)
    {

        long long num, r, t, mul = 1;
        num = t = i;
        r = 0;
        while (t != 0)
        {
            r = r * 10 + t % 10;
            t /= 10;
            mul *= 10;
        }
        num = num * mul + r;

        ans = (ans + num) % p;
    }
    cout << ans % p << endl;
    return 0;
}