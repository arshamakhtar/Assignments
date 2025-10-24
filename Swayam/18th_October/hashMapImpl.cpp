#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string,int> mp;

    // put operation
    mp["apple"] = 3;
    mp["banana"] = 2;

    // get operation
    cout << "apple count: " << mp["apple"] << endl;

    // containsKey
    cout << (mp.find("banana") != mp.end() ? "true" : "false") << endl;

    // keySet
    cout << "Keys: ";
    for (auto &p : mp) cout << p.first << " ";
}
