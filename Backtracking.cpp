#include <bits/stdc++.h>
using namespace std;

vector<bool> Isused(9);
void Print_Permutation(int pos, vector<int> &permutation, int n)
{
    if (pos > n)
    {
        for (int x : permutation)
            cout << x << " ";
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!Isused[i])
        {
            Isused[i] = true;
            permutation.push_back(i);
            Print_Permutation(pos + 1, permutation, n);
            Isused[i] = false;
            permutation.pop_back();
        }
    }
}

int main()
{

    int n;
    cin >> n;
    vector<int> permutation;

    Print_Permutation(1, permutation, n);

    return 0;
}