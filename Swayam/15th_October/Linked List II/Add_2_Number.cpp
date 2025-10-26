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
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Function: Add two numbers (digits stored in reverse order)
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* temp = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = 0;
        if (l1) { sum += l1->data; l1 = l1->next; }
        if (l2) { sum += l2->data; l2 = l2->next; }
        sum += carry;

        carry = sum / 10;
        temp->next = new Node(sum % 10);
        temp = temp->next;
    }

    return dummy->next;
}

int main() {
    Node* l1 = NULL;
    Node* l2 = NULL;
    int n1, n2, val;

    cout << "List1 me kitne digits? ";
    cin >> n1;
    cout << "Enter digits (reverse order): ";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        insertAtEnd(l1, val);
    }

    cout << "List2 me kitne digits? ";
    cin >> n2;
    cout << "Enter digits (reverse order): ";
    for (int i = 0; i < n2; i++) {
        cin >> val;
        insertAtEnd(l2, val);
    }

    cout << "Number 1: ";
    printList(l1);
    cout << "Number 2: ";
    printList(l2);

    Node* result = addTwoNumbers(l1, l2);
    cout << "Sum (in reverse order): ";
    printList(result);

    return 0;
}
