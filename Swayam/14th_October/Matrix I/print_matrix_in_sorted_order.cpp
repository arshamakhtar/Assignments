#include<iostream>
using namespace std;
int printarrayinsortedorder(int arr[], int n){
    // Simple Bubble Sort to sort the array
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Matrix elements in sorted order: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}int main(){
    int rows, cols;
    cout << "Enter the number of rows and columns in the matrix: ";
    cin >> rows >> cols;

    int matrix[100][100];
    cout << "Enter the elements of the matrix:" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> matrix[i][j];
        }
    }

    // Flatten the matrix into a single array
    int arr[10000]; // Assuming maximum size
    int index = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            arr[index++] = matrix[i][j];
        }
    }

    printarrayinsortedorder(arr, index);
    return 0;
}