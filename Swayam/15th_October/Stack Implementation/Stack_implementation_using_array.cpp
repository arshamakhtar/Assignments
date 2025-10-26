#include <bits/stdc++.h>
using namespace std;

class Stack {
    int *arr;
    int topIndex;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        topIndex = -1;
    }

    // push element
    void push(int x) {
        if (topIndex == capacity - 1) {
            cout << "Stack Overflow! \n";
            return;
        }
        arr[++topIndex] = x;
        cout << x << " pushed into stack\n";
    }

    // pop element
    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow! \n";
            return;
        }
        cout << arr[topIndex--] << " popped from stack\n";
    }

    // top element
    int top() {
        if (topIndex == -1) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[topIndex];
    }

    // check empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // print stack
    void display() {
        if (topIndex == -1) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = topIndex; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter stack size: ";
    cin >> n;

    Stack st(n);
    int choice, val;

    while (true) {
        cout << "\n1.Push  2.Pop  3.Top  4.Display  5.Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                st.push(val);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                cout << "Top element: " << st.top() << endl;
                break;
            case 4:
                st.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
