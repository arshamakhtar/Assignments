#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> st;      // normal stack
    stack<int> minSt;   // yeh stack minimum elements track karega

public:
    // Push operation
    void push(int val) {
        st.push(val);
        // Agar minStack empty hai ya new value min hai to usse bhi push karo
        if (minSt.empty() || val <= minSt.top())
            minSt.push(val);
    }

    // Pop operation
    void pop() {
        // Agar top element minStack ke top ke equal hai, dono se pop karo
        if (st.top() == minSt.top())
            minSt.pop();
        st.pop();
    }

    // Top element return karo
    int top() {
        return st.top();
    }

    // Minimum element O(1) time me return karo
    int getMin() {
        return minSt.top();
    }
};

int main() {
    MinStack s;
    int q;
    cin >> q; // operations ka count

    while (q--) {
        string op;
        cin >> op;

        if (op == "push") {
            int val;
            cin >> val;
            s.push(val);
        } else if (op == "pop") {
            s.pop();
        } else if (op == "top") {
            cout << s.top() << endl;
        } else if (op == "getMin") {
            cout << s.getMin() << endl;
        }
    }
    return 0;
}
