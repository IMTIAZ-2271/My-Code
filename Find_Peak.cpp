#include <iostream>
#include <vector>
using namespace std;

int find_peak(vector<vector<int>> &arr, 
              int colLow, int colHigh, int n)
{
    int colMid = colLow + (colHigh - colLow) / 2;

    int maxRow = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[maxRow][colMid] < arr[i][colMid])
        {
            maxRow = i;
        }
    }
    if (arr[maxRow][colMid - 1] <= arr[maxRow][colMid] && 
        arr[maxRow][colMid + 1] <= arr[maxRow][colMid])
    {
        return arr[maxRow][colMid];
    }
    else if (arr[maxRow][colMid - 1] > arr[maxRow][colMid])
    {
        return find_peak(arr, colLow, colMid - 1, n);
    }
    else
    {
        return find_peak(arr, colMid + 1, colHigh, n);
    }
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(n,0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    cout << "PEAK : "<<find_peak(arr,0,n-1,n);

    return 0;

}