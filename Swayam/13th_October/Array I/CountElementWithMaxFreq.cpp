#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int freq[1000] = {0};
    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
    }
    int maxFreq = 0;
    for(int i = 0; i < 1000; i++){
        if(freq[i] > maxFreq){
            maxFreq = freq[i];
        }
    }
    int count = 0;
    for(int i = 0; i < 1000; i++){
        if(freq[i] == maxFreq){
            count++;
        }
    }
    cout << "Number of elements with maximum frequency: " << count << endl;
    return 0;
}