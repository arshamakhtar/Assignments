#include <bits/stdc++.h>
using namespace std;

// Ye function longest subarray ka length return karta hai jisme 
// equal number of 0s aur 1s hote hain
int findMaxLength(vector<int>& nums) {
    vector<int> arr(2 * nums.size() + 1, INT_MIN);
    arr[nums.size()] = -1; // sum = 0 ke liye initial mapping
    int maxLen = 0, sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        // Agar element 0 hai to -1 add karo, aur agar 1 hai to +1
        sum += (nums[i] == 0 ? -1 : 1);

        // Agar pehle same sum mil chuka hai, toh subarray ka sum 0 hai
        if (arr[sum + nums.size()] >= -1)
            maxLen = max(maxLen, i - arr[sum + nums.size()]);
        else
            arr[sum + nums.size()] = i; // Pehli baar ye sum mila, toh index store karo
    }
    return maxLen; // Longest balanced subarray ki length return karo
}

int main() {
    int n;
    cin >> n; // Array ka size input lo
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i]; // Array ke elements lo
    
    cout << findMaxLength(nums); // Result print karo
    return 0;
}
