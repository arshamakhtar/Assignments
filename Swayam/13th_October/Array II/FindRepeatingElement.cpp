#include <iostream>
#include <algorithm> // For the sort function
#include <vector>

using namespace std;

// Function to find repeating elements using sorting
void findRepeatingElements_Easy(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) {
        cout << "The array is too small to have duplicates." << endl;
        return;
    }

    // 1. Sort the array. Now, duplicates will be adjacent.
    sort(arr.begin(), arr.end());

    cout << "The repeating elements are: ";
    bool found_duplicate = false;

    // 2. Iterate through the sorted array once.
    for (int i = 0; i < n - 1; i++) {
        // If the current element equals the next element, it's a duplicate.
        if (arr[i] == arr[i + 1]) {
            cout << arr[i] << " ";
            found_duplicate = true;

            // Optional: Skip all subsequent duplicates of the current number (e.g., skips the second '4' in '4 4 4')
            while (i < n - 1 && arr[i] == arr[i + 1]) {
                i++;
            }
        }
    }

    if (!found_duplicate) {
        cout << "None";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements (N): ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid size." << endl;
        return 1;
    }

    // Use vector for dynamic size.
    vector<int> arr(n);
    cout << "Enter the " << n << " elements: ";

    // Input loop
    for (int i = 0; i < n; i++) {
        if (!(cin >> arr[i])) {
            cerr << "Invalid input." << endl;
            return 1;
        }
    }

    // Find and print repeating elements
    findRepeatingElements_Easy(arr);

    return 0;
}