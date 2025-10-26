#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

bool searchNode(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key)
            return true; // Mil gaya
        temp = temp->next;
    }
    return false; // Nahi mila
}

int main() {
    Node* head = NULL;
    int n, val;

    cout << "Kitne nodes chahiye? ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(head, val);
    }

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    if (searchNode(head, key))
        cout << "✅ Node found!" << endl;
    else
        cout << "❌ Node not found!" << endl;

    return 0;
}
