#include<iostream>

using namespace std;
void findMaxAndMin(int arr[], int n, int &maxElement, int &minElement) {
    maxElement = arr[0];
    minElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }
}   int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int maxElement, minElement;
    findMaxAndMin(arr, n, maxElement, minElement);
    cout << "Maximum element: " << maxElement << endl;
    cout << "Minimum element: " << minElement << endl;
    return 0;
}