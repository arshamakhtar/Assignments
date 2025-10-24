#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
    vector<int> q;
    int front, rear, size, cap;

public:
    MyCircularQueue(int k) {
        q.resize(k);
        cap = k;
        size = 0;
        front = 0;
        rear = -1;
    }

    // 🟢 Enqueue element
    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % cap;
        q[rear] = value;
        size++;
        return true;
    }

    // 🔴 Dequeue element
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % cap;
        size--;
        return true;
    }

    // 👀 Front element
    int Front() {
        if (isEmpty()) return -1;
        return q[front];
    }

    // 👀 Rear element
    int Rear() {
        if (isEmpty()) return -1;
        return q[rear];
    }

    bool isEmpty() { return size == 0; }
    bool isFull() { return size == cap; }
};

int main() {
    int n;  // capacity
    cin >> n;
    MyCircularQueue cq(n);

    int q;  // number of operations
    cin >> q;

    while (q--) {
        string op;
        cin >> op;
        if (op == "push") {
            int val;
            cin >> val;
            cout << (cq.enQueue(val) ? "true" : "false") << endl;
        } else if (op == "pop") {
            cout << (cq.deQueue() ? "true" : "false") << endl;
        } else if (op == "front") {
            cout << cq.Front() << endl;
        } else if (op == "rear") {
            cout << cq.Rear() << endl;
        }
    }
}
