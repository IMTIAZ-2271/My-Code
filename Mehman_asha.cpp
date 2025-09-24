#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long N, x, y;
    cin >> N >> x >> y;
    long long s = 1;
    long long e = (x + y) / N;
    long long ans = 0;
   // long long k = 1;
    while (s<=e)
    {
        long long mid = (s + e ) / 2;
        //cout <<k<< "-->"<< s << " " << mid << " " << e << endl;
        
        if (x / mid + y / mid >= N)
        {
            ans = mid;
            s = mid+1 ;
        }
        else
        {
            e = mid-1;
        }
       // k++;
    }
    cout << ans << endl;
    return 0;
}