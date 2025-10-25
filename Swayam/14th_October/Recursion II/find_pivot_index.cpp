#include<iostream>
using namespace std;
int pivotIndex(int arr[], int n, int leftSum = 0, int rightSum = 0, int index = 0){
    if(index == n){
        return -1; // No pivot index found
    }
    rightSum = 0;
    for(int i = index + 1; i < n; i++){
        rightSum += arr[i];
    }
    if(leftSum == rightSum){
        return index; // Pivot index found
    }
    leftSum += arr[index];
    return pivotIndex(arr, n, leftSum, rightSum, index + 1);
}
int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int pivot = pivotIndex(arr, n);
    if(pivot != -1){
        cout << "The pivot index is: " << pivot << endl;
    } else {
        cout << "No pivot index found." << endl;
    }
    return 0;
}