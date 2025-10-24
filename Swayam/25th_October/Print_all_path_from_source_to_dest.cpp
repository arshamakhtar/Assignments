#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int> path, int node, int n) {
        path.push_back(node);
        
        // If target reached, save path
        if (node == n - 1) {
            ans.push_back(path);
            return;
        }
        
        // Explore all neighbors
        for (auto adjNode : graph[node]) {
            dfs(graph, ans, path, adjNode, n);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = graph.size();
        dfs(graph, ans, path, 0, n);
        return ans;
    }
};

/*
Time complexity: O(2ⁿ) in the worst case (each node can branch into multiple paths)
Space complexity: O(n) for recursion + current path
*/

// Driver code
int main() {
    Solution sol;
    
    // Graph: 0->1,2  1->3  2->3  3->end
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    
    vector<vector<int>> paths = sol.allPathsSourceTarget(graph);
    
    // Print all paths
    cout << "All paths from source to target:" << endl;
    for (const auto& path : paths) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
    
    return 0;
}
