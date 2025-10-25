#include<iostream>
using namespace std;
int sumofArray(int arr[], int n){
    if(n <= 0){
        return 0;
    }
    return arr[n - 1] + sumofArray(arr, n - 1);
}int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int sum = sumofArray(arr, n);
    cout << "The sum of the array elements is: " << sum << endl;
    return 0;
}