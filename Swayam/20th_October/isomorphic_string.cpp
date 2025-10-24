#include <bits/stdc++.h>
using namespace std;

// Ye function check karta hai ki do strings isomorphic hain ya nahi
bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;

    unordered_map<char, char> mp1, mp2;

    for (int i = 0; i < s.size(); i++) {
        char a = s[i], b = t[i];
        // Agar mapping exist karti hai toh woh match karni chahiye
        if ((mp1.count(a) && mp1[a] != b) || (mp2.count(b) && mp2[b] != a))
            return false;
        // Nahi toh mapping bana do
        mp1[a] = b;
        mp2[b] = a;
    }
    return true;
}

int main() {
    string s, t;
    cin >> s >> t; // Dono strings input lo

    if (isIsomorphic(s, t))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
