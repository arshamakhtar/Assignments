#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;

    for (char ch : exp) {
        if (isdigit(ch)) {
            st.push(ch - '0'); // convert char → int
        } else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                default: cout << "Invalid operator!\n"; return -1;
            }
        }
    }
    return st.top();
}

int main() {
    string exp;
    cout << "Enter postfix expression (single digit operands): ";
    cin >> exp;

    cout << "Result = " << evaluatePostfix(exp) << endl;

    return 0;
}
