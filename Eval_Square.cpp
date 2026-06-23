#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

long long EvalSquare(vector<long long> &A, long long int n)
{
    if (n == 1)
        return A[0] * A[0];

    long long int mid = n / 2;
    vector<long long> A1(A.begin(), A.begin() + mid);
    vector<long long> A2(A.begin() + mid, A.end());

    long long a1 = EvalSquare(A1, mid);
    long long a2 = EvalSquare(A2, n - mid);
    long long a1_plus_a2 = (a1 + a2);
    long long cross = pow(a1_plus_a2,2) - pow(a1,2) - pow(a2,2);

    return a1*a1*pow(10,n) + cross*pow(10,mid) + a2*a2;


}