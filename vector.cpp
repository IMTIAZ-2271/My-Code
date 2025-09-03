#include<bits/stdc++.h>
using namespace std;
int main()
{   
    /*int n; cin >>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    v.erase(unique(v.begin(),v.end()),v.end());

    //unique() function arrange all unique elements in the given vector at the first of the vector.
    // It arranges all thing in the given numbers int the given order.



    for(int in:v){cout << in << " ";}
    cout << endl;*/

    int n; cin >> n;
    int k; cin >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    k = k % n; // handle k > n
    // Rotate right by k positions using reverse
    reverse(v.begin(), v.end());
    reverse(v.begin(), v.begin() + k);
    reverse(v.begin() + k, v.end());

    for(int j = 0; j < n; j++) {
        cout << v[j] << " ";
    }

    return 0;

}