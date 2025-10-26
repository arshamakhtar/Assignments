#include <bits/stdc++.h>
using namespace std;

// Linked List ka ek node
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function: given position par naya node insert karna
void insertAtPosition(Node*& head, int data, int position) {
    Node* newNode = new Node(data);

    // Agar position 1 hai toh head ke aage insert karna hai
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    int count = 1;

    // Position tak pahunchne ke liye traverse karte hain
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    // Agar position invalid hai (list khatam ho gayi)
    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        delete newNode;
        return;
    }

    // Insert karna (new node ko link adjust)
    newNode->next = temp->next;
    temp->next = newNode;
}

// Helper function: list print karna
void printList(Node* head) {
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver Code
int main() {
    Node* head = NULL;

    // Pehle kuch nodes manually add karte hain
    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "Before insertion: ";
    printList(head);

    int data, pos;
    cout << "Enter data to insert: ";
    cin >> data;
    cout << "Enter position: ";
    cin >> pos;

    insertAtPosition(head, data, pos);

    cout << "After insertion: ";
    printList(head);

    return 0;
}
