#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        // First row and first column are all 1 (only one way)
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];  // From top + from left
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;
    cout << "Unique Paths (3x3): " << sol.uniquePaths(3,3) << endl; // Output: 6
    cout << "Unique Paths (7x3): " << sol.uniquePaths(7,3) << endl; // Output: 28
    return 0;
}
