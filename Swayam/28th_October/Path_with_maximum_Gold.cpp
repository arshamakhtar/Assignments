#include <bits/stdc++.h>
using namespace std;

// Helper (DFS) function to collect gold from current cell
int dfs(vector<vector<int>> &grid, int x, int y) {
    int n = grid.size(), m = grid[0].size();

    // Agar grid ke bahar ho ya gold nahi hai toh 0 return karo
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0)
        return 0;

    int gold = grid[x][y];
    grid[x][y] = 0; // Visited mark kar diya, dobara nahi aayenge

    // Char directions me explore karo -- left, right, up, down
    int left = dfs(grid, x, y - 1);
    int right = dfs(grid, x, y + 1);
    int up = dfs(grid, x - 1, y);
    int down = dfs(grid, x + 1, y);

    // Wapas aane se pehle original gold restore karo (backtracking)
    grid[x][y] = gold;

    // Maximum path value calculate karo
    return gold + max(max(left, right), max(up, down));
}

int getMaximumGold(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    int maxGold = 0;

    // Har cell se start karke max gold calculate karo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] > 0) {
                maxGold = max(maxGold, dfs(grid, i, j));
            }
        }
    }
    return maxGold;
}

// Driver code
int main() {
    vector<vector<int>> grid = {
        {0,6,0},
        {5,8,7},
        {0,9,0}
    };

    cout << "Maximum gold collectable: " << getMaximumGold(grid) << endl;
    // Output: 24

    vector<vector<int>> grid2 = {
        {1, 0, 7},
        {2, 0, 6},
        {3, 4, 5},
        {0, 3, 0},
        {9, 0, 20}
    };

    cout << "Maximum gold collectable (test 2): " << getMaximumGold(grid2) << endl;
    // Output: 28

    return 0;
}
