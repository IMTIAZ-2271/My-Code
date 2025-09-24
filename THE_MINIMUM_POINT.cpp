#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double d;
int main()
{
    d ax , ay , az;
    cin >> ax >> ay >> az;
    d bx , by , bz;
    cin >> bx >> by >> bz;
    d cx , cy , cz;
    cin >> cx >> cy >> cz;

    double CA = sqrt(pow(cx - ax,2) + pow((cy - ay),2) + pow((cz - az),2));
    double BA = sqrt(pow(bx - ax,2) + pow((by - ay),2) + pow((bz - az),2));
    double CB = sqrt(pow(cx - bx,2) + pow((cy - by),2) + pow((cz - bz),2));

    double x = 0.0;

    double l = 0.0;
    double r = BA;
    double ans = x ;
    while(l<=r)
    {
        double mid = (l + r)/2.0 ;
        double x = BA - sqrt( CA * CA - mid * mid ) -  sqrt( CB * CB - mid * mid );
        if(x > 0.0+1e-9)
        {
            r = mid - 1e-9 ;
        }
        else{
             ans = mid;
             l = mid + 1e-9;
        }
    }
    cout <<fixed<<  setprecision(8)<<ans << endl;

    return 0;

}