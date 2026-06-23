// In number theory, a perfect number is a positive integer
// that is equal to the sum of its positive divisors,
// excluding the number itself.
// For instance, 6 has divisors 1, 2 and 3(excluding itself), and 1 + 2 + 3 = 6,
// so 6 is a perfect number. Given a number N, check if it is a perfect number
// or not.

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
bool isPerfectNumber(long long N) {
  if (N <= 1) {
    return false;
  }
  long long sum = 1;
  for (long long i = 2; i * i <= N; i++) {
    if (N % i == 0) {
      if (i == N / i) {
        sum += i;
      } else {
        sum += (i + N / i);
      }
    }
  }
  return sum == N;
}
int main() {
  long long x;
  cin >> x;
  if (isPerfectNumber(x)) {
    cout << "PERFECT" << endl;
  } else {
    cout << "UGLY" << endl;
  }
  return 0;
}