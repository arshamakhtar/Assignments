#include <bits/stdc++.h>
using namespace std;

// 0 se n tak numbers diye hain, ek missing hai, usse dhoondo
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int ans = n; // 0 xor 1 xor ... xor n, and all array elements bhi xor karo
    for (int i = 0; i < n; i++)
        ans ^= i ^ nums[i];
    return ans;
}

int main() {
    int n;
    cin >> n; // Array ka size lo
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << missingNumber(nums) << endl; // Missing number print karo
    return 0;
}
