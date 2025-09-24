#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    unordered_map<long long, int> freq;
    vector<long long> result;
    long long k = 0;

    // Count frequencies in first array
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        freq[x]++;
    }

    // Process second array directly
    for (int i = 0; i < m; i++) {
        long long x; cin >> x;
        if (freq[x] > 0) {
            result.push_back(x);
            freq[x]--;
            k++;
        }
    }
    sort(result.begin(),result.end());

    cout << k << "\n";
    for (auto &x : result) cout << x << " ";
    cout << "\n";

    return 0;
}





// ** This is my solution.
/*#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    map<long long, int> a, b;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < m; i++) {
        long long x;
        cin >> x;
        b[x]++;
    }

    auto it1 = a.begin();
    auto it2 = b.begin();
    vector<long long> result;
    int k = 0;

    while (it1 != a.end() && it2 != b.end()) {
        if (it1->first == it2->first) {
            int cnt = min(it1->second, it2->second);
            k += cnt;
            for (int i = 0; i < cnt; i++) result.push_back(it1->first);
            ++it1;
            ++it2;
        } else if (it1->first < it2->first) {
            ++it1;
        } else {
            ++it2;
        }
    }

    cout << k << "\n";
    for (auto &x : result) cout << x << " ";
    cout << "\n";

    return 0;
}
*/