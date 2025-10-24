#include <bits/stdc++.h>
using namespace std;

// Priority queue banao (default max heap)
priority_queue<int> pq;

// Ye function element ko enqueue karta hai
void insert(int x) {
    pq.push(x); // element add karo
}

// Maximum element ko delete karo
void removeMax() {
    if (!pq.empty()) {
        pq.pop(); // sabse bada element delete karo
    }
}

// Check karo kya x queue me hai ya nahi
void find(int x) {
    priority_queue<int> temp = pq; // temp copy banao
    bool found = false;
    while (!temp.empty()) {
        if (temp.top() == x) {
            found = true;
            break;
        }
        temp.pop();
    }
    if (found)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main() {
    int q; // operations ki value
    cin >> q;
    while(q--) {
        string op;
        cin >> op;
        if (op == "Insert") {
            int x;
            cin >> x;
            insert(x);
        } else if (op == "Delete") {
            removeMax();
        } else if (op == "Find") {
            int x;
            cin >> x;
            find(x);
        }
    }
    return 0;
}
