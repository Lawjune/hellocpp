#include <iostream>
#include <utility>

using namespace std;

class Obj {
public:
    Obj() { cout << "Obj()" << endl; }

    Obj(const Obj &) { cout << "Obj(Obj&)" << endl; }
};

Obj simple()
{
    Obj obj;

    // Simply return object; 
    // Before c++11, returning a local variable means this object will be copied
    // unless the complier found that NRVO(named return value optimization) available
    // Since c++11, if the NRVO is not available, 
    // complier will move the local variable out but not copying it out.
    return obj;
}

Obj simple_with_move()
{
    Obj obj;
    // move will forbit NRVO, not recommended
    return std::move(obj);
}

Obj complicated(int n)
{
    Obj obj1;
    Obj obj2;

    // Usually the branch would not support NRVO
    if (n % 2 == 0) {
        return obj1;
    } else {
        return obj2;
    }
}

void test_return_local_variable() 
{
     cout << "*** 1 ***" << endl;  
     auto obj1 = simple();  
     cout << "*** 2 ***" << endl;  
     auto obj2 = simple_with_move();  
     cout << "*** 3 ***" << endl;  
     auto obj3 = complicated(42);
}