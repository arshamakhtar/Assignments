#include <bits/stdc++.h>
using namespace std;

// Ye function max heapify karta hai ek node ko
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;       // abhi ke liye assume karo root largest hai
    int left = 2 * i + 1;  // left child index
    int right = 2 * i + 2; // right child index

    // Agar left child bada hai toh largest update karo
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Agar right child bada hai toh largest update karo
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Agar largest root nahi hai toh swap karo aur recursively heapify karo
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // recursive call for the affected subtree
    }
}

// Array ko max heap me convert karo
void buildHeap(vector<int>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// Heap Sort function array ko sort karta hai in-place
void heapSort(vector<int>& arr, int n) {
    buildHeap(arr, n); // Pehle heap banao

    // Ek ek karke elements ko heap se nikaalo
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // current root ko end pe bhejo
        heapify(arr, i, 0);   // reduced heap ko heapify karo
    }
}

int main() {
    int n;
    cin >> n; // Array ka size input lo
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i]; // Element input lo

    heapSort(arr, n); // Heap Sort karo

    // Sorted array print karo
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
