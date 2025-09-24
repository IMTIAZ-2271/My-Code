#include <bits/stdc++.h>
using namespace std;
#define hurryup                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

typedef long long ll;

bool comp(const vector<int> &a, const vector<int> &b) {
    int limit = min(a.size(), b.size());
    for (int i = 0; i < limit; i++) {
        if (a[i] != b[i]) 
            return a[i] > b[i];
    }
    return a.size() > b.size(); 
}

int main() {
    hurryup;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> input(n);
        vector<vector<int>> input_copy(n);
        int max_length = 0;

        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            max_length = max(max_length, k);
            for (int j = 0; j < k; j++) {
                int val;
                cin >> val;
                input[i].push_back(val);
            }
        }
        input_copy = input;

        sort(input.begin(), input.end(), comp);
        //int temp_size = input[n-1].size();
        vector<int> result = input[n-1];
        for(int i=n-1; i>=0 && result.size()<max_length; i--)
        {
            if(input_copy[i].size()>result.size())
            {
                int temp_size = result.size();
                for(int j=temp_size; j<input_copy[i].size(); j++)
                {
                    result.push_back(input_copy[i][j]);
                }
            }
        }
        for (int val : result) {
            cout << val << " ";
        }
        cout << "\n";

    }

    return 0;
}
