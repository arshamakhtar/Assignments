#include <bits/stdc++.h>
using namespace std;

// Cycle detection technique se duplicate number find karo
int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];
    // Pehle do pointer cycle milne tak move karo
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Reset slow, ab ek step chalao, jaha milenge wahi duplicate hai
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main() {
    int n;
    cin >> n; // Size input lo
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i]; // Array input
    cout << findDuplicate(nums) << endl; // Duplicate number print karo
    return 0;
}
