#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function for linear house robber
    int rob_linear(vector<int>& nums, int start, int end) {
        int prev = 0, curr = 0;
        for (int i = start; i < end; i++) {
            int temp = curr;
            // Ya toh previous (last house skip) ya iss wale loot ke do pehle ka add karo
            curr = max(curr, prev + nums[i]);
            prev = temp;
        }
        return curr;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        // Agar sirf ek house hai toh wahi loot lo
        if (n == 1) return nums[0];
        // Array ko do part mein split karo (group 1: 0..n-2 | group 2: 1..n-1)
        // Circular hone ki wajah se pehla ya last loot sakte ho, dono nahi
        int loot1 = rob_linear(nums, 0, n-1);
        int loot2 = rob_linear(nums, 1, n);
        return max(loot1, loot2);
    }
};

// Driver code to test House Robber II
int main() {
    Solution sol;
    // Test case 1
    vector<int> nums = {2, 3, 2};
    cout << "Max loot (circle): " << sol.rob(nums) << endl; // Output: 3

    // Test case 2
    vector<int> nums2 = {1, 2, 3, 1};
    cout << "Max loot (circle): " << sol.rob(nums2) << endl; // Output: 4

    // Test case 3
    vector<int> nums3 = {1,2,3};
    cout << "Max loot (circle): " << sol.rob(nums3) << endl; // Output: 3

    return 0;
}
