#include <bits/stdc++.h>
using namespace std;

// Heapify function ek node pe heap property maintain karta hai
void heapify(vector<int>& arr, int n, int i) {
    int smallest = i;          // Assume current node is the smallest
    int left = 2 * i + 1;      // left child index
    int right = 2 * i + 2;     // right child index

    // Left child chota hai toh update karo
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // Right child chota hai toh update karo
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // Agar smallest current index nahi hai, toh swap karo aur recursive call karo
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);  // Recursively child ko heapify karo
    }
}

// Min Heap build karne ke liye bottom-up approach use karo
void buildHeap(vector<int>& arr, int n) {
    // Last non-leaf node se start karo aur sabko heapify karo
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int main() {
    int n;
    cin >> n; // Array ka size input lo
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i]; // Array elements input lo

    buildHeap(arr, n);  // Heap banao

    // Min-heap print kar do
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
