#include <string>
#include <ctime>
#include <chrono>
#include <iostream>

void func1(std::string s)
{
}

void func2(const std::string &s)
{
}

void func3(std::string &&s)
{
}

void test2()
{
    std::string s = std::string("hello"); 
    
    auto start = std::chrono::system_clock::now();
    for (size_t i = 0; i < 20000000; i++)
    {
        func1(s);
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    start = std::chrono::system_clock::now();
    for (size_t i = 0; i < 20000000; i++)
    {
        func2(s);
    }
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    start = std::chrono::system_clock::now();
    for (size_t i = 0; i < 20000000; i++)
    {
        func3(std::move(s));
    }
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

int main()
{
    test2();
}