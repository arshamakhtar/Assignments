#include <iostream>

using namespace std;

// Function to remove duplicates from a sorted array in-place.
int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1) {
        return n; // Handle empty or single-element array.
    }

    int j = 0; // Pointer for the next unique element's position.

    // Iterate up to the second-to-last element (n-2).
    for (int i = 0; i < n - 1; i++) {
        // If the current element is NOT equal to the next one, it's unique.
        if (arr[i] != arr[i + 1]) {
            arr[j] = arr[i]; // Copy the unique element to position 'j'.
            j++;             // Move the unique pointer forward.
        }
    }

    // The last element (arr[n-1]) is always unique and must be added.
    arr[j] = arr[n - 1];

    return j + 1; // The new size of the array.
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int newSize = removeDuplicates(arr, n);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}