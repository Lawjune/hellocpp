#include <stdio.h>
#include "shape.h"

class Result 
{
public:
    Result() { puts("Result()"); }
    ~Result() { puts("~Result()"); }
};

Result process_shape(const Shape& shape1, const Shape& shape2)
{
    puts("process_shape()");
    return Result();
}

void test_process_shape()
{
    puts("test_process_shape() with lvalue");
    process_shape(Circle(), Triangle());
    puts("Something else...");
    puts("Something else...");
    puts("Something else...");
    puts("test_process_shape() with prvalue");
    Result&& r = process_shape(Circle(), Triangle());
    puts("Something else...");
}