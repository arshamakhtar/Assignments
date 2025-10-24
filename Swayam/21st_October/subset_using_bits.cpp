#include <bits/stdc++.h>
using namespace std;

// Ye function array ke saare possible subsets (power set) nikalta hai
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size();
    int total = 1 << n; // 2^n subsets hote hain
    for (int mask = 0; mask < total; mask++) {
        vector<int> subset;
        // Har bit check karo, jo set hai usse subset me daalo
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) subset.push_back(nums[i]);
        }
        res.push_back(subset);
    }
    return res;
}

int main() {
    int n;
    cin >> n; // Array ka size lo
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<vector<int>> ans = subsets(nums);
    // Har subset print karo
    for (auto& vec : ans) {
        for (int x : vec) cout << x << " ";
        cout << endl;
    }
    return 0;
}
