#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        // Boundary check and land check
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 1) {
            return;
        }
        
        // Mark as visited
        grid[i][j] = 1;
        
        // Explore all 4 directions
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Remove all islands touching borders (they are not closed)
        for (int i = 0; i < rows; i++) {
            if (grid[i][0] == 0) dfs(grid, i, 0);           // Left border
            if (grid[i][cols - 1] == 0) dfs(grid, i, cols - 1);  // Right border
        }
        for (int j = 0; j < cols; j++) {
            if (grid[0][j] == 0) dfs(grid, 0, j);           // Top border
            if (grid[rows - 1][j] == 0) dfs(grid, rows - 1, j);  // Bottom border
        }
        
        // Count remaining closed islands
        int closedIslands = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    closedIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return closedIslands;
    }
};

// Driver code
int main() {
    Solution sol;
    
    // Test Case 1: 2 closed islands
    vector<vector<int>> grid1 = {
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0}
    };
    cout << "Number of closed islands: " << sol.closedIsland(grid1) << endl;
    // Output: 2
    
    // Test Case 2: 1 closed island
    vector<vector<int>> grid2 = {
        {0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0}
    };
    cout << "Number of closed islands: " << sol.closedIsland(grid2) << endl;
    // Output: 1
    
    return 0;
}
