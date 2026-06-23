#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double calrate(double r, int t)
{
    if (t == 0)
        return 1.000000000000000000000000000000;
    if (t % 2 == 1)
        return r * calrate(r, t - 1);
    double ans = calrate(r, t / 2);
    return ans * ans;
}
// 060 722 383 550 382 782 399 454 922 040
// 060722420224237794172950088978
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, t;
    cin >> N >> t;
    double r = 1.000000011;

    cout << fixed << setprecision(30) << (double)N * calrate(r, t) << endl;
    return 0;
}