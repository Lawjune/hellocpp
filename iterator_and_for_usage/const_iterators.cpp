#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void print_regular_iterator(vector<int>& v)
{
    // Declare a regular iterator to a vector
    vector<int>::iterator i;

    // Printing the elements of the vector v using regular iterator
    for (i = v.begin(); i < v.end(); i++) {
        // Update the elements of vector
        *i += 1;
        cout << *i << " ";
    }
}

void print_const_iterator(vector<int>& v)
{
    // Declare a const_iterator to a vector
    vector<int>::const_iterator ci;

    // Printing the elements of the vector v using const iterator
    for (ci = v.begin(); ci < v.end(); ci++)
    {
        // *c1 += 1; // Error
        cout << *ci << " ";
    }
}

int main()
{
    vector<int> v = {4, 7, 14, 28};
    vector<int> v1 = {4, 7, 14, 28};
    print_regular_iterator(v);
    cout << endl;

    print_const_iterator(v);
    cout << endl;

    print_const_iterator(v1);
    cout << endl;

    return 0;
}