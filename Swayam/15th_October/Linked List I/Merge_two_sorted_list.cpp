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

// Function: Merge two sorted linked lists
Node* mergeSortedLists(Node* l1, Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    Node* result = NULL;

    if (l1->data <= l2->data) {
        result = l1;
        result->next = mergeSortedLists(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeSortedLists(l1, l2->next);
    }

    return result;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    int n1, n2, val;

    cout << "List 1 ke kitne nodes? ";
    cin >> n1;
    cout << "Enter sorted elements for List 1: ";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        insertAtEnd(list1, val);
    }

    cout << "List 2 ke kitne nodes? ";
    cin >> n2;
    cout << "Enter sorted elements for List 2: ";
    for (int i = 0; i < n2; i++) {
        cin >> val;
        insertAtEnd(list2, val);
    }

    cout << "\nList 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    Node* merged = mergeSortedLists(list1, list2);

    cout << "\nMerged Sorted List: ";
    printList(merged);

    return 0;
}
