#include <stdio.h>
#include "shape.h"

// T& must be lvaue reference
// T&& might not be rvalue reference

// template <typename T> foo(T&&) 
//   If passing a lvalue, T would be processed as lvalue reference
//   If passing a rvalue, T would be processed as the type reference of input parameter


void foo(const Shape&)
{
    puts("foo(const Shape&)");
}

void foo(Shape&&)
{
    puts("foo(Shape&&)");
}

void bar(const Shape& s)
{
    puts("bar(const Shape&)");
    foo(s);
}

void bar(Shape&& s)
{
    puts("bar(Shape&&)");
    // foo(s);
    foo(std::move(s));
    // foo(static_cast<shape &&>(s));
}

template <typename T>
void bar(T&& s)
{
    foo(std::forward<T>(s));
}

void test_ref_folded()
{
    bar(Circle());
}

void test_forward()
{
    Circle temp;
    bar(temp);
    bar(Circle());
}