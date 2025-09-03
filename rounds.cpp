#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int x;

        cin >> n;
        int k = 0;
        int a[10];
        int i = 0;
        while (n != 0)
        {
            x = n % 10;
            if (x != 0)
            {
                k++;
            }
            a[i++] = x;
            n /= 10;
        }
        cout << k << endl;
        for (int j = 0; j < i; j++)
        {
            if (a[j] != 0)
            {
                cout << a[j] * pow(10, j) << endl;
            }
        }
    }
    return 0;
}