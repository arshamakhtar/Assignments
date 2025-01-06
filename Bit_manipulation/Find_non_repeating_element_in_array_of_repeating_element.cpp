#include <iostream>
#include <vector>
using namespace std;

pair<int, int> find(vector<int>& nums) {
    int xor_all = 0;
    for (int num : nums) {
        xor_all ^= num;
    }

    int setbit = xor_all & (-xor_all);
    int x = 0, y = 0;

    for (int num : nums) {
        if (num & setbit) {
            x ^= num;
        } else {
            y ^= num;
        }
    }

    return {x, y};
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2, 3, 5, 5, 3, 6};
    auto result = find(nums);
    cout << "The two non-repeating elements: " << result.first << " and " << result.second << endl;
    return 0;
}
