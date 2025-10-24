#include <bits/stdc++.h>
using namespace std;

// Ye function array me har element ek baar ya do baar repeat hota hai,
// sirf ek element aisa hai jo single hai, usse dhundho
int singleNumber(vector<int>& nums) {
    int ans = 0;
    // XOR karne se, pairs zero ban jaayenge sirf single number bachega
    for (int x : nums) ans ^= x;
    return ans;
}

int main() {
    int n;
    cin >> n; // Kitne elements array mein hai
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i]; // Array ka input lo
    cout << singleNumber(nums) << endl; // Single number print karo
    return 0;
}
