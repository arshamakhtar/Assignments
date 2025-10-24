#include <bits/stdc++.h>
using namespace std;

// isBadVersion ka mock function (LeetCode me predefined hota hai)
int badVersion;
bool isBadVersion(int version) {
    return version >= badVersion;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isBadVersion(mid)) {
                ans = mid;      // mid bad hai to uske pehle check karo
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n >> badVersion; // total versions + pehla bad version

    Solution sol;
    cout << sol.firstBadVersion(n);
}
