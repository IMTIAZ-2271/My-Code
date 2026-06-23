#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long x, y, a, b;
    cin >> x >> y >> a >> b;
    long long lcm = x*(y/__gcd(x,y));

    cout << (b / lcm) - ((a-1)/lcm) << endl;
    return 0;
}