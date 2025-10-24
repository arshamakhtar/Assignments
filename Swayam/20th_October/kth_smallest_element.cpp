#include <bits/stdc++.h>
using namespace std;

// Ye function min heap bana ke kth smallest deta hai
int findKthSmallest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Sare elements heap me push karo
    for(int num : nums) minHeap.push(num);

    // k-1 baar top ko pop karo
    for(int i = 1; i < k; i++) minHeap.pop();

    return minHeap.top();
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cout << findKthSmallest(nums, k) << endl;
    return 0;
}
