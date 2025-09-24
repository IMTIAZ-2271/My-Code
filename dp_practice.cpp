#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long int> freq(100005,0);
    for(int i=0; i<n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    vector<long long int> sum(100005,0);
    for(int i=1; i<100005; i++){
        sum[i]=sum[i-1]+1LL*i*freq[i];
    }
    int q; cin >> q;
    while(q--){
        int L,R; cin >> L >> R;
        cout << sum[R]-sum[L-1] << endl;
    }
    return 0;
}