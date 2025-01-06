#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> powerSet(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;

    for (int i = 0; i < (1 << n); i++) {
        vector<int> sub;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) sub.push_back(nums[j]);
        }
        res.push_back(sub);
    }

    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = powerSet(nums);
    
    for (const auto& sub : res) {
        for (int num : sub) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
