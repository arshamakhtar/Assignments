#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int k;
    int n;
    cin>>n>>k;
vector<int>arr;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin()+k);     
    reverse(arr.begin()+k,arr.end());
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}