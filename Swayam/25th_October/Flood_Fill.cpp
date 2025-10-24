#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int originalColor) {
        // Boundary check and color match check
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || 
            image[sr][sc] != originalColor) {
            return;
        }
        
        // Fill with new color
        image[sr][sc] = newColor;
        
        // Flood fill in all 4 directions
        dfs(image, sr + 1, sc, newColor, originalColor);  // Down
        dfs(image, sr - 1, sc, newColor, originalColor);  // Up
        dfs(image, sr, sc + 1, newColor, originalColor);  // Right
        dfs(image, sr, sc - 1, newColor, originalColor);  // Left
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        
        // Avoid infinite loop if colors are same
        if (originalColor != newColor) {
            dfs(image, sr, sc, newColor, originalColor);
        }
        
        return image;
    }
};

// Driver code
int main() {
    Solution sol;
    
    // Test Case 1
    vector<vector<int>> image1 = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr1 = 1, sc1 = 1, newColor1 = 2;
    
    vector<vector<int>> result1 = sol.floodFill(image1, sr1, sc1, newColor1);
    
    cout << "After flood fill:" << endl;
    for (auto& row : result1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    // Output: [[2,2,2],[2,2,0],[2,0,1]]
    
    return 0;
}
