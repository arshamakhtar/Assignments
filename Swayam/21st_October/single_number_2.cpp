#include <bits/stdc++.h>
using namespace std;

// Array me har element 3 baar aata hai, ek value single aata hai
// Har bit ka count nikaal ke, mod 3 se jo bacha use result me set karo
int singleNumber2(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int bitCount = 0;
        for (int x : nums) {
            if (x & (1 << i)) bitCount++;
        }
        if (bitCount % 3) { // Agar bitCount 3 ka multiple nahi toh answer me set karo
            ans |= (1 << i);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << singleNumber2(nums) << endl; // Unique element print karo
    return 0;
}
