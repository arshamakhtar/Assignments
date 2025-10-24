#include <bits/stdc++.h>

using namespace std;

// This function uses DFS (Depth First Search) to check if a path exists from 'node' to 'destination'
bool dfs(int node, int destination, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true; // Mark the current node as visited

    if (node == destination) return true; // If we reach the destination, return true

    // Traverse all neighbors of the current node
    for (int neighbor : adj[node]) {
        // If the neighbor hasn't been visited, recursively check for a path
        if (!visited[neighbor]) {
            if (dfs(neighbor, destination, adj, visited))
                return true; // If any recursive call finds the path, return true
        }
    }
    return false; // If no path is found, return false
}

// Main function to determine if a valid path exists
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> adj(n); // Create an adjacency list for the graph
    // Convert the edge list to an adjacency list (since the graph is bidirectional, add for both nodes)
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    vector<bool> visited(n, false); // Visited array to keep track of visited nodes and avoid cycles

    // Use DFS to check if a path from source to destination exists
    return dfs(source, destination, adj, visited);
}

// Example driver code
int main() {
    // Test Case 1
    int n1 = 3;
    vector<vector<int>> edges1 = {{0,1},{1,2},{2,0}};
    int source1 = 0, destination1 = 2;
    cout << "Test 1: " << (validPath(n1, edges1, source1, destination1) ? "true" : "false") << endl;
    // Output: true

    // Test Case 2
    int n2 = 6;
    vector<vector<int>> edges2 = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    int source2 = 0, destination2 = 5;
    cout << "Test 2: " << (validPath(n2, edges2, source2, destination2) ? "true" : "false") << endl;
    // Output: false

    return 0;
}

// Output
// Test 1: true
// Test 2: false