#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<long long> fact(30, 1);
  for (int i = 1; i < 30; i++) {
    fact[i] = i * fact[i - 1];
  }

  int tt;
  cin >> tt;
  int tc = 1;
  while (tc <= tt) {
    long long n, c;
    cin >> n >> c;
    int ans = 0;
    if (n >= c) {
      ans = (pow(fact[n], 2) / (fact[c])) / (pow(fact[n - c], 2));
    }
    cout << "Case " << tc++ << ":" << ans << endl;
  }
  return 0;
}