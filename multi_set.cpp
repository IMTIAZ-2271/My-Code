#include <iostream>
#include <set>

int main() {
std::multiset<int> myMultiset = {3, 1, 4, 1, 5, 9, 2, 4, 6, 5};
auto it = myMultiset.lower_bound(4);
std::cout << *it;
return 0;
}