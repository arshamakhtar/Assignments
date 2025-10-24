#include <bits/stdc++.h>
using namespace std;

/*
    Depth-First Search (DFS) Traversal in a Graph

    DFS explores as far as possible along each branch before backtracking.
    It can be implemented recursively or iteratively (using a stack).

    This version uses recursion for simplicity.

    Time Complexity:  O(V + E)
    Space Complexity: O(V)
    - V = number of vertices
    - E = number of edges
*/

// Recursive DFS function
void dfsUtil(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " "; // Process current node

    // Explore unvisited neighbors
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, adj, visited);
        }
    }
}

// DFS traversal driver function
void dfsTraversal(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    cout << "DFS Traversal starting from node " << start << ": ";
    dfsUtil(start, adj, visited);
    cout << "\n";
}

int main() {
    int V = 5; // Number of vertices (0..V-1)
    vector<vector<int>> adj(V);

    // Lambda function to add edges (undirected)
    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    // Add edges
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);

    // Print adjacency list
    cout << "Adjacency List:\n";
    for (int i = 0; i < V; ++i) {
        cout << i << " -> ";
        for (int v : adj[i]) cout << v << " ";
        cout << "\n";
    }
    cout << "\n";

    // Perform DFS starting from node 0
    dfsTraversal(0, adj, V);

    return 0;
}
//Adjacency List:
// 0 -> 1 4
// 1 -> 0 2 3 4
// 2 -> 1 3
// 3 -> 1 2 4
// 4 -> 0 1 3

// DFS Traversal starting from node 0: 0 1 2 3 4