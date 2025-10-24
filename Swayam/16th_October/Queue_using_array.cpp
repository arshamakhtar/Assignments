#include <bits/stdc++.h>
using namespace std;

class Queue {
    int *arr;
    int front, rear, size, capacity;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[cap];
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isFull() { return size == capacity; }
    bool isEmpty() { return size == 0; }

    // 🟢 Enqueue operation (insert element)
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
    }

    // 🔴 Dequeue operation (remove element)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    // 👀 Get front element
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

int main() {
    int cap, q;
    cin >> cap >> q;  // capacity and number of operations

    Queue qu(cap);

    while (q--) {
        string op;
        cin >> op;

        if (op == "push") {
            int val;
            cin >> val;
            qu.enqueue(val);
        } else if (op == "pop") {
            qu.dequeue();
        } else if (op == "front") {
            cout << qu.getFront() << endl;
        }
    }
}
