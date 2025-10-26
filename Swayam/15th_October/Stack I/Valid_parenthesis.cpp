#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) return false; // closing bracket pehle aaya

            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{'))
                return false;
        }
    }

    return st.empty(); // agar sab balance hue to stack empty
}

int main() {
    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    if (isValid(s))
        cout << "✅ Valid Parentheses\n";
    else
        cout << "❌ Invalid Parentheses\n";

    return 0;
}
