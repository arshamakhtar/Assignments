#include <bits/stdc++.h>
using namespace std;

// Sliding window maximum nikaalne ka function
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;  // Indexes store karta hai, values nahi
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Window ke bahar ke elements hatao
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        // Chhote elements ko piche se hatao, kyunki wo kabhi answer nahi banenge
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        
        dq.push_back(i); // Current index insert karo

        // Window puri ban chuki hai toh result me maximum daalo
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k; // Array ka size aur window size lo
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i]; // Array input

    vector<int> ans = maxSlidingWindow(nums, k); // Function call

    for (int x : ans) cout << x << " "; // Output result
    cout << endl;
    return 0;
}
