#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // If starting cell is blocked, no paths
        if (obstacleGrid[0][0] == 1) return 0;
        
        dp[0][0] = 1;
        
        // First column setup
        for(int i=1;i<m;i++)
            dp[i][0] = (obstacleGrid[i][0]==0) ? dp[i-1][0] : 0;
        
        // First row setup
        for(int j=1;j<n;j++)
            dp[0][j] = (obstacleGrid[0][j]==0) ? dp[0][j-1] : 0;
        
        // Fill the dp grid
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j]==0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else{
                    dp[i][j] = 0;  // blocked cell
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    Solution sol;
    vector<vector<int>> obstacleGrid = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    cout << "Unique Paths with Obstacles: " << sol.uniquePathsWithObstacles(obstacleGrid) << endl; // Output: 2
    return 0;
}
