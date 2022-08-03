
#include <iostream>
// #include <memory> // std::pair
// #include <map>
// #include <set>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <list>
// #include <queue>
// #include <stack>
// #include <tuple> // std::tie
// #include <functional> // std::less/greater/hash
#include <complex.h> // std::complex
#include <unordered_map> // std::unordered_map
#include <unordered_set> // std::unordered_set
#include <iterator> // std::size
#include "output_container.h"

using namespace std;


// array

// C old method should not be used in c++
// #define ARRAY_LEN(a) (sizeof(a) / sizeof(a)[0])

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  cout << "The array length is " << std::size(arr) << endl;
}

// Understand the unordered containers in c++

// namespace std {

//   template <typename T>
//   struct hash<complex<T>> 
//   {
//     size_t operator()(const complex<T>& v) const noexcept
//     {
//       hash<T> h;
//       return h(v.real()) + h(v.imag());
//     }
//   };
  
// } // namespace std

// int main()
// {
//   unordered_set<int> s{1, 1, 2, 3, 5, 8, 13, 21};
//   cout << "unordered_set: " << s << endl;

//   unordered_map<complex<double>, double> umc{{{1.0, 1.0}, 1.4142}, {{3.0, 4.0}, 5.0}};
//   cout << "unordered_map: " << umc << endl;
// }

// Understand the ordered containers in c++
// int main()
// {
//   set<int> s{1, 1, 1, 2, 3, 4};
//   cout << "s: " << s << endl;
//   // s: { 1, 2, 3, 4 }

//   multiset<int, greater<int>> ms{1, 1, 1, 2, 3, 4};
//   cout << "ms: " << ms << endl;
//   // ms: { 4, 3, 2, 1, 1, 1 }

//   map<string, int> mp{
//       {"one", 1},
//       {"two", 2},
//       {"three", 3},
//       {"four", 4}
//   };

//   cout << "mp: " << mp << endl;
//   // mp: { four => 4, one => 1, three => 3, two => 2 }
//   mp.insert({"four", 4});
//   cout << "mp: " << mp << endl;

//   // cout << "mp.end(): " << mp.end() << endl;
//   // cout << "mp.find(\"four\"): " << mp.find("four") << endl;
//   cout << "mp.find(\"four\") == mp.end(): " << (mp.find("four") == mp.end()) << endl;
//   cout << "mp.find(\"five\") == mp.end(): " << (mp.find("five") == mp.end()) << endl;
//   mp["five"] = 5;
//   cout << "added 5 mp: " << mp << endl;

//   cout << std::string(49, '-') << endl;
//   cout << std::string(49, '-') << endl;

//   multimap<string, int> mmp{
//     {"one", 1},
//     {"two", 2},
//     {"three", 3},
//     {"four", 4}
//   };

//   cout << "mmp: " << mmp << endl;
//   mmp.insert({"four", -4}); // Allow to add duplicated keys
//   cout << "mmp: " << mmp << endl;

//   cout << std::string(49, '-') << endl;
//   cout << std::string(49, '-') << endl;

//   cout << "mp.find(\"two\")->first: " << mp.find("two")->first << endl;
//   cout << "mp.find(\"two\")->second: " << mp.find("two")->second << endl;
//   cout << "mp.find(\"four\")->second: " << mp.find("four")->second << endl;

//   cout << "(mp.upper_bound(\"four\"))->first: " << (mp.upper_bound("four"))->first << endl;
//   cout << "(--mp.upper_bound(\"four\"))->second: " << (--mp.upper_bound("four"))->second << endl;

//   cout << "mmp.lower_bound(\"four\")->second: " << mmp.lower_bound("four")->second << endl;
//   cout << "(--mmp.lower_bound(\"four\"))->second: " << (--mmp.lower_bound("four"))->second << endl;
//   cout << "(--mmp.upper_bound(\"four\"))->second: " << (--mmp.upper_bound("four"))->second << endl;

//   cout << std::string(49, '-') << endl;
//   cout << std::string(49, '-') << endl;

//   multimap<string, int>::iterator lower, upper;
//   std::tie(lower, upper) = mmp.equal_range("four");
//   cout << "((lower != upper)): " << (lower != upper) << endl;
//   cout << "lower->second: " << lower->second << endl;
//   cout << "(--upper)->second: " << (--upper)->second << endl;
// }

// priority_queue
// int main() 
// {
//   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
//   q.push({1, 1});
//   q.push({2, 2});
//   q.push({0, 3});
//   q.push({9, 4});

//   while (!q.empty())
//   {
//     cout << q.top() << endl;
//     q.pop();
//   }
// }

// int main()
// {
//   vector<int> v{13, 6, 4, 11, 29};
//   cout << v << endl;

//   sort(v.begin(), v.end());
//   cout << v << endl;

//   sort(v.begin(), v.end(), greater<int>());
//   cout << v << endl;

//   cout << hex;

//   auto hp = hash<int *>();
//   cout << "hash(nullptr) = " << hp(nullptr) << endl;
//   cout << "hash(v.data()) = " << hp(v.data()) << endl;
//   cout << "v.data()      = " << static_cast<void*>(v.data()) << endl;

//   auto hs = hash<string>();
//   cout << "hash(\"hello\") = " << hs(string("hello")) << endl;
//   cout << "hash(\"hellp\") = " << hs(string("hellp")) << endl;
// }

// // The implementation of less
// template <class T>
// struct less : binary_function<T, T, bool> {
//   bool operator()(const T& x, const T& y) const
//   {
//     return x < y;
//   }
// }

// // The implementation of hash
// template <class T>
// struct hash;

// template <>
// struct hash<int> : public unary_function<int, size_t> {
//   size_t operator()(int v) const noexcept {
//     return static_cast<size_t>(v);
//   }
// }

// int main() 
// {
//   std::stack<int> s;
//   s.push(1);
//   s.push(2);
//   s.push(3);
//   while (!s.empty()) 
//   {
//     cout << s.top() << endl;
//     s.pop();
//   }
// }
// // output:
// // 3
// // 2
// // 1

// int main()
// {
//   std::queue<int> q;
//   q.push(1);
//   q.push(2);
//   q.push(3);
//   while (!q.empty()) 
//   {
//     cout << q.front() << endl;
//     q.pop();
//   }
// }
// output
// 1
// 2
// 3

// list
// int main() 
// {
//   list<int> lst{1, 7, 2, 8, 3};
//   vector<int> vec{1, 7, 2, 8, 3};

//   sort(vec.begin(), vec.end());
//   // sort(lst.begin(), lst.end()); // Error
//   lst.sort();

//   cout << lst << endl;
//   // output: { 1, 2, 3, 7, 8 }

//   cout << vec << endl;
//   // output: { 1, 2, 3, 7, 8 }
// }

// vehicle emplace_back() using moved pointer
// class Obj1 {
// public:
//   Obj1() { cout << "Obj1()\n"; }
//   Obj1(const Obj1 &) { cout << "Obj1(const Obj1&)\n"; }
//   Obj1(Obj1 &&) { cout << "Obj1(Obj1&&)\n"; }
// };

// class Obj2 {
// public:
//   Obj2() { cout << "Obj2()\n"; }
//   Obj2(const Obj2 &) { cout << "Obj2(const Obj2&)\n"; }
//   Obj2(Obj2 &&) noexcept { cout << "Obj2(Obj2&&)\n"; }
// };

// int main()
// {
//   vector<Obj1> v1;
//   v1.reserve(2);
//   v1.emplace_back();
//   v1.emplace_back();
//   v1.emplace_back();
//   // output:
//   // Obj1()
//   // Obj1()
//   // Obj1()
//   // Obj1(const Obj1&)
//   // Obj1(const Obj1&)

//   vector<Obj2> v2;
//   v2.reserve(2);
//   v2.emplace_back();
//   v2.emplace_back();
//   v2.emplace_back();
//   // output:
//   // Obj2()
//   // Obj2()
//   // Obj2()
//   // Obj2(Obj2&&)
//   // Obj2(Obj2&&)

// }

// int main()
// {
//   map<int, int> mp{
//     {1, 1}, {2, 4}, {3, 9}};
//   cout << mp << endl;
//   vector<vector<int>> vv{
//     {1, 1}, {2, 4}, {3, 9}};
//   cout << vv << endl;
// }
// output:
// { 1 => 1, 2 => 4, 3 => 9 }
// { { 1, 1 }, { 2, 4 }, { 3, 9 } }