#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int mod = 1e9 + 7;
const int N = 10000;
int fact[N + 1];

void init_fact()
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        fact[i] = (1LL * i * fact[i - 1]) % mod;
    }
}
int binpow(int a, int p)
{
    if (p == 0)
    {
        return 1;
    }
    if (p % 2 == 0)
    {
        int r = binpow(a, p / 2) % mod;
        return (1LL * r * r) % mod;
    }
    return (1LL * binpow(a, p - 1) % mod * a) % mod;
}

int modinv(int a) // from fermat's little theorem.
{
    return binpow(a, mod - 2);
}

int nCr(int n, int r)
{
    int a = fact[n];
    int b = modinv(fact[r]);
    int c = modinv(fact[n - r]);
    cout << a << " " << b << " " << c << endl;
    int ans = (1LL * a * b) % mod;
    ans = (1LL * ans * c) % mod;
    return ans;
}

int main()
{

    init_fact();
    cout << nCr(4,2) << endl;
    return 0;
}