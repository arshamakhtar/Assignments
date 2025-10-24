#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i=0;i<n;i++) cin >> nums[i];

    int count = 0, candidate = 0;

    for(int num : nums) {
        if(count == 0) candidate = num;
        if(num == candidate) count++;
        else count--;
    }

    // verify candidate
    int freq = 0;
    for(int num : nums) if(num == candidate) freq++;

    if(freq > n/2) cout << "Majority Element: " << candidate << endl;
    else cout << "No Majority Element exists." << endl;

    return 0;
}
