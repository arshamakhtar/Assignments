#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str); // string input lene ke liye

    string original = str;
    string reversed = str;
    reverse(reversed.begin(), reversed.end()); // string ko reverse kar diya

    // Compare karte hain original aur reversed ko
    if(original == reversed)
        cout << "Yes! Ye string palindrome hai." << endl;
    else
        cout << "No! Ye string palindrome nahi hai." << endl;

    return 0;
}
