#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // DP table where dp[i][j] = min path sum to cell (i,j)
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[0][0] = grid[0][0];  // start point ka value
        
        // Pehle row fill karo (sirf right move kar sakte hain)
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        
        // Pehle column fill karo (sirf down move kar sakte hain)
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
        // Baaki sab cells ke liye min of top ya left cell ka plus current grid value
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[m-1][n-1]; // Bottom-right cell mein minimum path sum hai
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    cout << "Minimum Path Sum: " << sol.minPathSum(grid) << endl; // Output: 7
    return 0;
}
