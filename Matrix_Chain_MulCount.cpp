#include <iostream>
#include <vector>
#include <climits>
using namespace std;

static int count = 1;
void printOptimalParens(const vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A"<< i << " ";
    } else {
    
        cout << "( ";
        
        printOptimalParens(s, i, s[i][j]);
        
        printOptimalParens(s, s[i][j] + 1, j);
        
        cout << ")";
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0; 
    
    vector<int> p(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1; 
            
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                    
                    s[i][j] = k; 
                }
            }
        }
    }

    cout << "Minimum Cost: " << dp[1][n] << "\n";
    
    cout << "Optimal Parenthesization: ";
    printOptimalParens(s, 1, n);
    cout << "\n";
    
    return 0;
}