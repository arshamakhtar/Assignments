#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // current element
        int j = i - 1;

        // left side se compare karte hue correct position pe insert karo
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // shift
            j--;
        }
        arr[j + 1] = key; // insert key at right position
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    insertionSort(arr, n);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
