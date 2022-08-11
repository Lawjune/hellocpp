#include <iostream>
#include <algorithm> // std::copy
#include <iterator> // std::back_inserter
#include <vector> // std::vector
#include "../output_container.h"

using namespace std;

int main()
{
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2;

    copy(v1.begin(), v1.end(), back_inserter(v2));
    cout << "v2: " << v2 << endl;

    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    

    return 0;
}