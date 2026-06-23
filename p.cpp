// Demonstrate a vector.
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;
int main()
{
    vector<char> v(10); // create a vector of length 10
    unsigned int i;
   
    cout << "Size = " << v.size() << endl;
    cout << "Capacity = " << v.capacity() << endl;
    
    for (i = 0; i < 10; i++)
        v[i] = i + 'a';
    // display contents of vector
    cout << "Current Contents:\n";
    for (i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n\n";
    /* put more values onto the end of the vector, it will grow as needed */
    cout << "Expanding vector\n";
    for (i = 0; i < 5; i++)
        v.push_back(i + 10 + 'a');
    // display current size of v
    cout << "Size now = " << v.size() << endl;
    cout << "Capacity = " << v.capacity() << endl;
    // display contents of vector
    cout << "Current contents:\n";
    for (i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n\n";
    // change contents of vector
    for (i = 0; i < v.size(); i++)
        v[i] = toupper(v[i]);
    cout << "Modified Contents:\n";
    for (i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}