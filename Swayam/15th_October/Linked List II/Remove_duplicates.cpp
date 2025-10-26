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

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function: Remove duplicates from sorted linked list
Node* removeDuplicates(Node* head) {
    Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data) {
            Node* dup = curr->next;
            curr->next = curr->next->next;
            delete dup;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

int main() {
    Node* head = NULL;
    int n, val;

    cout << "Kitne nodes chahiye (sorted order): ";
    cin >> n;
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(head, val);
    }

    cout << "Original List: ";
    printList(head);

    head = removeDuplicates(head);

    cout << "After removing duplicates: ";
    printList(head);

    return 0;
}
