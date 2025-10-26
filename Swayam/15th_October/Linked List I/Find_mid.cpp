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

// Function: Find middle node using slow-fast pointer method
Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;       // 1 step
        fast = fast->next->next; // 2 steps
    }

    return slow; // slow ab middle par hoga
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
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

    cout << "Linked List: ";
    printList(head);

    Node* mid = findMiddle(head);
    if (mid)
        cout << "Middle Node: " << mid->data << endl;
    else
        cout << "List empty hai!" << endl;

    return 0;
}
