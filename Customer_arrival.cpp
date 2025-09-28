


/*You are given the arrival and leaving times of n customers in a restaurant.
What was the maximum number of customers in the restaurant at any time?
Input
The first input line has an integer n: the number of customers.
After this, there are n lines that describe the customers. 
Each line has two integers a and b: the arrival and leaving times of a customer.
You may assume that all arrival and leaving times are distinct.
Output
Print one integer: the maximum number of customers.
Constraints

1 <= n <= 2*10^5
1 <= a < b <= 10^9

Example
Input:
3
5 8
2 4
3 9

Output:
2
*/


#include<bits/stdc++.h>
using namespace std;
#define hurryup ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
typedef long long int ll;

int main()
{
    hurryup;
    ll n;
    cin >> n;

    vector<pair<ll,int>> a; // {time, +1 for arrival / -1 for departure}

    for(int i = 0 ; i < n ; i++){
        ll arrive, depart;
        cin >> arrive >> depart;
        a.push_back({arrive, +1});  // arrival event
        a.push_back({depart, -1});  // departure event
    }

    // Sort events by time; if equal, -1 (departure) comes before +1 (arrival) automatically
    sort(a.begin(), a.end());

    ll curr = 0, ans = 0;

    // Sweep through events
    for(auto &e : a){
        curr += e.second;        // +1 for arrival, -1 for departure
        ans = max(ans, curr);    // track maximum
    }

    cout << ans << "\n";
    return 0;
}
/*Ai ans:

#include<bits/stdc++.h>
using namespace std;
#define hurryup ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
typedef long long int ll;

int main()
{
    hurryup;
    ll n;
    cin >> n;

    vector<ll> arrive(n), depart(n);

    // Input arrivals and departures
    for(int i = 0 ; i < n ; i++){
        cin >> arrive[i] >> depart[i];
    }

    // Sort both arrays
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());

    ll curr = 0, ans = 0;
    ll i = 0, j = 0;

    // Two-pointer sweep
    while(i < n && j < n){
        if(arrive[i] < depart[j]){
            // A customer arrives
            curr++;
            ans = max(ans, curr);
            i++;
        }
        else{
            // A customer leaves
            curr--;
            j++;
        }
    }

    cout << ans << "\n";
    return 0;
}
*/
