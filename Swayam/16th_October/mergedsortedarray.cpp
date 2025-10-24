#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;

        // piche se merge kar rahe hain
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // agar nums2 ke elements bache hain
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> nums1(m + n), nums2(n);
    for (int i = 0; i < m; i++) cin >> nums1[i];
    for (int i = 0; i < n; i++) cin >> nums2[i];

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    for (int x : nums1) cout << x << " ";
}
