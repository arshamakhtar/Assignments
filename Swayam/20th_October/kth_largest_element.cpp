#include <bits/stdc++.h>
using namespace std;

// Ye function k-th largest element dhoondta hai array me
int findKthLargest(vector<int>& nums, int k) {
    // Pehle k elements se min heap banao
    priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.begin() + k);

    // Baaki elements ka check karo
    for (int i = k; i < nums.size(); i++) {
        // Agar current element heap ke top se bada hai
        if (minHeap.top() < nums[i]) {
            minHeap.pop();        // Chota element hatao
            minHeap.push(nums[i]); // Naya bada element daalo
        }
    }
    return minHeap.top(); // Min heap ka top hi k-th largest hai
}

int main() {
    int n, k;
    cin >> n >> k; // Input array ka size aur k lo
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i]; // Array ke elements input lo
    cout << findKthLargest(nums, k); // k-th largest element print karo
    return 0;
}
