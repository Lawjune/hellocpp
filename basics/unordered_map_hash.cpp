#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

void print_freq(const string &str)
{
    // Each word is mapped to its frequence
    unordered_map<string, int> word_freq;

    // Breaking inout into word using string stream
    stringstream ss(str); // Used for breaing words
    string word; // To store individual words

    while (ss >> word)
    {
        word_freq[word]++;
    }

    unordered_map<string, int>::iterator p;
    for (p = word_freq.begin(); p != word_freq.end(); p++)
        cout << "(" << p->first << ", " << p->second << ")\n";
}

int main()
{
    string str = "geeks for geeks geeks quiz "
                 "practice qa for";
    print_freq(str);
    return 0;
}

// Example 2
// void find_key(unordered_map<string, double> umap, string key);
// int main()
// {
//     unordered_map<string, double> umap;

//     umap["PI"] = 3.14;
//     umap["root2"] = 1.414;
//     umap["root3"] = 1.732;
//     umap["log10"] = 2.302;
//     umap["loge"] = 1.0;

//     umap.insert(make_pair("e", 2.718));

//     string key = "PI";
//     find_key(umap, key);

//     key = "lambda";
//     find_key(umap, key);

//     unordered_map<string, double>::iterator itr;
//     cout << "\nAll Elements: \n";
//     for (itr = umap.begin(); itr != umap.end(); itr++)
//     {
//         cout << itr->first << " " << itr->second << endl;
//     }
// }

// void find_key(unordered_map<string, double> umap, string key)
// {
//     if (umap.find(key) == umap.end())
//         cout << key << " not found\n\n";
//     else
//         cout << "Found " << key << endl;
// }

// Example 1
// int main() 
// {
//     unordered_map<string, int> umap;

//     umap["KEY_A"] = 10;
//     umap["KEY_B"] = 20;
//     umap["KEY_C"] = 30;

//     // Traversing an unordered map
//     for (auto x : umap)
//         cout << x.first << " " << x.second << endl;

//     return 0;
// }

