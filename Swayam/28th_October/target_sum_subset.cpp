#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        // sum aur target se subset sum banta hai:
        // s2 = (sum - target)/2, yeh valid hona chahiye (even and >= 0)
        if (sum < target || (sum - target) % 2 != 0) return 0;
        int s2 = (sum - target) / 2;
        
        return subsetSum(nums, s2);
    }
private:
    int subsetSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        
        // Base condition: empty subset se sum 0 ban sakta hai 1 way se
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        
        for (int i = 1; i <= n; i++){
            for (int j = 0; j <= target; j++) {
                if (nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j - nums[i-1]] + dp[i-1][j]; // include or exclude
                else
                    dp[i][j] = dp[i-1][j]; // exclude only
            }
        }
        return dp[n][target];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << "Number of ways: " << sol.findTargetSumWays(nums, target) << endl; // Output: 5
    return 0;
}
