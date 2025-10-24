#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // number -> index

        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];

            // agar need pehle se map me hai, to answer mil gaya
            if (mp.find(need) != mp.end()) {
                return {mp[need], i};
            }

            // warna current number ko map me store kar do
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);

    if (!ans.empty())
        cout << ans[0] << " " << ans[1];
    else
        cout << "No pair found";
}
