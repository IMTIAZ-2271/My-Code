#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main() {
    int n = 100000;
    int m = 500000;

    // Create a text file to write to
    ofstream out("massive_input.txt");
    
    out << n << " " << m << "\n";

    mt19937 rng(1337); // Random number generator
    for (int i = 0; i < m; ++i) {
        // To guarantee NO CYCLES, edges always go from smaller ID to larger ID
        int u = uniform_int_distribution<int>(1, n - 1)(rng);
        int v = uniform_int_distribution<int>(u + 1, n)(rng);
        out << u << " " << v << "\n";
    }

    out.close();
    cout << "massive_input.txt generated successfully!" << endl;
    return 0;
}