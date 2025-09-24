#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left[], int lsz, int right[], int rsz)
{
    int l = 0, r = 0, i = 0;

    while (l < lsz && r < rsz)
    {
        if (left[l] <= right[r])
        {
            arr[i] = left[l];
            l++;
        }
        else
        {
            arr[i] = right[r];
            r++;
        }
        i++;
    }

    while (l < lsz)
    {
        arr[i] = left[l];
        l++;
        i++;
    }
    while (r < rsz)
    {
        arr[i] = right[r];
        r++;
        i++;
    }
}
void mergesort(int arr[], int size)
{

    if (size == 1)
    {
        return;
    }
    int mid = size / 2;

    int lsz = mid;
    int rsz = size - mid;
    int left[lsz], right[rsz];

    for (int i = 0; i < lsz; i++)
        left[i] = arr[i];

    for (int j = 0; j < rsz; j++)
        right[j] = arr[lsz + j];

    mergesort(left, lsz);
    mergesort(right, rsz);

    merge(arr, left, lsz, right, rsz);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    int input[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    mergesort(input, n);

    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (input[i] != input[i - 1])
            cnt++;
    }
    cout << cnt << endl;

    return 0;
}