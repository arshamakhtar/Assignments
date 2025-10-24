#include <bits/stdc++.h>
using namespace std;

// Backtracking se har permutation print karo
void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& curr, vector<vector<int>>& res) {
    if (curr.size() == nums.size()) {
        res.push_back(curr);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums, used, curr, res); // Recurse karte jao
            curr.pop_back(); // Wapas aate waqt pop karo
            used[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> curr;
    vector<bool> used(nums.size(), false);
    backtrack(nums, used, curr, res);
    return res;
}

int main() {
    int n;
    cin >> n; // Array size input lo
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<vector<int>> ans = permute(nums);
    for (auto& vec : ans) {
        for (int x : vec) cout << x << " ";
        cout << endl;
    }
    return 0;
}
