#include<bits/stdc++.h>
using namespace std;

// DP approach: maximum money without robbing two adjacent houses
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // Agar koi house hi nahi hai, 0 return karo
        if(n == 0) return 0;
        // Ek hi house hai toh wahi loot lo
        if(n == 1) return nums[0];
        
        // DP array: dp[i] mein maximum paisa jo house i tak loot sakte ho bina adjacent loote
        vector<int> dp(n, 0);
        
        dp[0] = nums[0];           // Pehla house loot lo
        dp[1] = max(nums[0], nums[1]); // Doosre tak best option choose karo
        
        // Har house ke liye, lootne ya skip karne ka best option
        for(int i = 2; i < n; i++) {
            // Ya toh previous house tak ka paisa (agar yeh house skip kiya)
            // Ya is house ko loot ke (and usse pehle wale par rok ke) ka paisa + current house ka paisa
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[n-1];
    }
};

// Driver code (input-output example)
int main() {
    Solution sol;
    // Test case: har ghar mein kitna paisa hai
    vector<int> nums = {2, 7, 9, 3, 1};
    int answer = sol.rob(nums);
    cout << "Maximum loot possible: " << answer << endl; // Output: 12
    
    // Ek aur test case
    vector<int> nums2 = {1, 2, 3, 1};
    cout << "Maximum loot (test 2): " << sol.rob(nums2) << endl; // Output: 4
    
    return 0;
}
