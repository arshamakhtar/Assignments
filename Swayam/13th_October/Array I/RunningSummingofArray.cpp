#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>arr;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }
    vector<int>runningSum(n,0);
    runningSum[0]=arr[0];
    for(int i=1;i<n;i++){
        runningSum[i]=runningSum[i-1]+arr[i];
    }
    cout<<"Running sum of the array: ";
    for(int i=0;i<n;i++){
        cout<<runningSum[i]<<" ";
    }
    cout<<endl;
    return 0;
}
