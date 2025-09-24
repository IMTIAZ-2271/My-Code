#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<string,int>> students(n);
    for(int i = 0; i < n; i++) {
        cin >> students[i].first;
        students[i].second = i;
    }

    
    sort(students.begin(), students.end());

    
    vector<int> roll(n);
    for(int i = 0; i < n; i++) {
        roll[students[i].second] = i + 1; 
    }
    for(int i = 0; i < n; i++) {
        cout << roll[i] << " ";
    }
    cout << "\n";

    return 0;
}
