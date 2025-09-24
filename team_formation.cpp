#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; 
    cin >> n;
    vector<long long int > a(3*n);
    for(int i=0; i<3*n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    long long int sum =0;
    for(int i=0; i<3*n-2; i+=3)
    {
        sum+=a[i+2]-a[i]+a[i+1]-a[i]+a[i+2]-a[i+1];
    }
    cout << sum << endl;

    return 0;

}

