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

// Function: Rotate the list by k places
Node* rotateRight(Node* head, int k) {
    if (!head || !head->next || k == 0)
        return head;

    // Step 1: Count nodes
    Node* temp = head;
    int len = 1;
    while (temp->next != NULL) {
        len++;
        temp = temp->next;
    }

    // Step 2: Make circular list
    temp->next = head;

    // Step 3: Effective rotations
    k = k % len;
    int stepsToNewHead = len - k;

    // Step 4: Move to new head
    Node* newTail = temp;
    while (stepsToNewHead--)
        newTail = newTail->next;

    Node* newHead = newTail->next;
    newTail->next = NULL; // break the circle

    return newHead;
}

int main() {
    Node* head = NULL;
    int n, val, k;

    cout << "Kitne nodes chahiye? ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(head, val);
    }

    cout << "Enter k (rotate by): ";
    cin >> k;

    cout << "Original List: ";
    printList(head);

    head = rotateRight(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}
