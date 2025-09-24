#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
#define getbit(n, i) (((n) & (1LL << (i))) != 0) 
#define setbit0(n, i) ((n) & (~(1LL << (i)))) 
#define setbit1(n, i) ((n) | (1LL << (i))) 
#define togglebit(n, i) ((n) ^ (1LL << (i))) 
#define lastone(n) ((n) & (-(n))) 
char gap = 32;
#define int long long
#define ll long long 
#define lll __int128_t
#define pb push_back
typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll hashPrime = 1610612741;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    ordered_set os;
    for(int i = 1; i <= n; i++) {
        int v; cin >> v;
        os.insert({v, i});
    }
    int cnt = n + 1;
    int q; cin >> q;
    while(q--) {
        int tp; cin >> tp;
        if(tp == 1) {
            int x; cin >> x;
            os.insert({x, cnt});
            cnt++;
        }
        else {
            int l, r; cin >> l >> r;
            int ans = os.order_of_key({r + 1, 0}) - os.order_of_key({l, 0});
            cout << ans << "\n";
        }
    }
    return 0;
}