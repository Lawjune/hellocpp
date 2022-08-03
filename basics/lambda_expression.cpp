#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<int> v)
{
    // lambda expression to print vector
    for_each(v.begin(), v.end(), [](int i)
             { std::cout << i << " "; });
    cout << endl;
}

int main()
{
    vector<int> v{4, 1, 3, 5, 2, 3, 1, 7};

    print_vector(v);

    // Find the first number greater than 4
    vector<int>::iterator p = find_if(v.begin(), v.end(), [](int i)
                                      { return i > 4; });
    cout << "First number > 4 is: " << *p << endl;

    // Sort this vector
    sort(v.begin(), v.end(), [](const int &a, const int &b) -> bool
         { return a > b; });
    print_vector(v);

    // Get the counts of number >-= 5
    int count_5 = count_if(v.begin(), v.end(), [](int a)
                           { return (a >= 5); });
    cout << "The number of elements greater than or equal to 5 is: "
         << count_5 << endl;

    // Removing dulocated elements after sorting all duplicated comes together
    p = unique(v.begin(), v.end(), [](int a, int b)
               { return a == b; });
    
    // Resizing the vector to make size equal to total different number
    v.resize(distance(v.begin(), p));
    print_vector(v);

    // Accumulate the container on the basis of a function provided as the 3rd argument
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int f = accumulate(arr, arr + 10, 1, [](int i, int j)
                       { return i * j; });
    cout << "Factorial of 10 is: " << f << endl;

    auto square = [](int i)
    {
        return i * i;
    };
    cout << "Square of 5 is: " << square(5) << endl;

    return 0;
}