#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        
        // Visit all neighbors
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }
    
    int numIslands(int n, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        //first initialize everything to be unvisited
        vector<bool> visited(n, false);
        int islands = 0;
        
        // Count connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                islands++;  // Found new island/component
                dfs(i, adj, visited);
            }
        }
        
        return islands;
    }
};

// Driver code
int main() {
    Solution sol;
    
    // Test Case 1: 2 islands
    // Graph: 0-1-2 and 3-4 (2 components)
    int n1 = 5;
    vector<vector<int>> edges1 = {{0,1}, {1,2}, {3,4}};
    cout << "Number of islands: " << sol.numIslands(n1, edges1) << endl;
    // Output: 2
    
    // Test Case 2: 3 islands
    // Graph: 0-1, 2-3, 4 alone (3 components)
    int n2 = 5;
    vector<vector<int>> edges2 = {{0,1}, {2,3}};
    cout << "Number of islands: " << sol.numIslands(n2, edges2) << endl;
    // Output: 3
    
    // Test Case 3: 1 island (all connected)
    int n3 = 4;
    vector<vector<int>> edges3 = {{0,1}, {1,2}, {2,3}};
    cout << "Number of islands: " << sol.numIslands(n3, edges3) << endl;
    // Output: 1
    
    return 0;
}
