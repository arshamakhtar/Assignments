#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> s1, s2; // s1: input, s2: output

public:
    //  Push operation
    void push(int x) {
        s1.push(x);
    }

    //  Pop operation
    int pop() {
        if (s2.empty()) {
            // Agar s2 empty hai, s1 ke sab elements reverse order me daal do
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }

    //  Peek operation
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    //  Check empty
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    int q;
    cin >> q;
    MyQueue qu;

    while (q--) {
        string op;
        cin >> op;

        if (op == "push") {
            int val;
            cin >> val;
            qu.push(val);
        } else if (op == "pop") {
            cout << qu.pop() << endl;
        } else if (op == "peek") {
            cout << qu.peek() << endl;
        } else if (op == "empty") {
            cout << (qu.empty() ? "true" : "false") << endl;
        }
    }
}
