#include <bits/stdc++.h>
using namespace std;

/*
    Breadth-First Search (BFS) Traversal in a Graph

    BFS explores vertices level by level, starting from a given source node.
    It uses a queue to keep track of the next vertex to visit and ensures
    that each node is visited exactly once using a visited array.

    Time Complexity:  O(V + E)
    Space Complexity: O(V)
    - V = number of vertices
    - E = number of edges
*/

// Function to perform BFS traversal
void bfsTraversal(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);   // Track visited nodes
    queue<int> q;                     // Queue for BFS order

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal starting from node " << start << ": ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " "; // Process current node

        // Visit all unvisited neighbors
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
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

    // Perform BFS starting from node 0
    bfsTraversal(0, adj, V);

    return 0;
}
// Adjacency List:
// 0 -> 1 4
// 1 -> 0 2 3 4
// 2 -> 1 3
// 3 -> 1 2 4
// 4 -> 0 1 3

// BFS Traversal starting from node 0: 0 1 4 2 3