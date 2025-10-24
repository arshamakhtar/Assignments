#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[city] = true;
        
        // Visit all directly connected cities
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[city][i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;
        
        // Count connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces++;  // Found new province
                dfs(i, isConnected, visited);
            }
        }
        
        return provinces;
    }
};

// Driver code
int main() {
    Solution sol;
    
    // Test Case 1: 2 provinces
    vector<vector<int>> isConnected1 = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    cout << "Number of provinces: " << sol.findCircleNum(isConnected1) << endl;
    // Output: 2
    
    // Test Case 2: 3 provinces
    vector<vector<int>> isConnected2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    cout << "Number of provinces: " << sol.findCircleNum(isConnected2) << endl;
    // Output: 3
    
    return 0;
}
