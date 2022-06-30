#include <iostream>
#include "ref_folded.h"
// #include "donot_return_ref_of_local_var.h"
// #include "process_shape.h"
// #include "unique_ptr.h"
// #include "shared_ptr.h"
// #include "shape.h"

int main() 
{
    std::cout << "Hello World!" << std::endl;

    // test_uqniue_ptr();
    // test_shared_ptr();
    // test_process_shape();
    // test_return_local_variable();
    test_forward();
}