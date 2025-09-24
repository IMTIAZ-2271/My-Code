#include <bits/stdc++.h>

#define pb             push_back
#define endl "\n" 
#define fill(x, y)     memset(x, y, sizeof(x))
#define all(x)         (x).begin(), (x).end()
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define IO	       { ios_base::sync_with_stdio(false); cin.tie(0); }
#define read(x)	       freopen(x, "r", stdin)
#define write(x)       freopen(x, "w", stdout)

using namespace std;

typedef long long      ll;
typedef pair<int, int> ii;
typedef vector<int>    vi;

bool check(int dist, int n, vi a) {
    int m = a.size();
    int placed = 1, lastPos = a[0];
    for (int i=1; i<m; i++) 
    {
        if (a[i] - lastPos >= dist)
        {
            lastPos = a[i];
            placed++;
        }
    }
    return (placed >= n);
}

int main() {


    int n, m;
    cin >> n >> m;

    vector<int> position(m);
    for (int i=0; i<m; i++)
    {
        cin >> position[i];
    }
    sort(all(position));
    int low = 0, high = 1e9;
     
    long long ans = 0;
    while(low <= high) 
    {
        int mid = (low + high ) / 2;
        if (check(mid, n, position))
        {
            ans = mid;
            low = mid + 1;
        } 
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;
} 