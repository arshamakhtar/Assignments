#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string result = "";

    for(char ch : str) {
        if(isalpha(ch)) result += ch; // sirf alphabet characters ko rakhte hain
    }

    cout << "String after removing non-alphabets: " << result << endl;

    return 0;
}

