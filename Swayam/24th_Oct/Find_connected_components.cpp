#include <bits/stdc++.h>
using namespace std;

/*
    Finding Connected Components in an Undirected Graph

    A connected component is a set of vertices that are all reachable from each other.
    DFS (or BFS) can be used to find and label all such components.

    Time Complexity:  O(V + E)
    Space Complexity: O(V)
    - V = number of vertices
    - E = number of edges
*/

// Recursive DFS utility function
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, component);
        }
    }
}

// Function to find all connected components
void findConnectedComponents(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    int componentCount = 0;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, adj, visited, component);
            componentCount++;

            cout << "Component " << componentCount << ": ";
            for (int node : component) cout << node << " ";
            cout << "\n";
        }
    }

    cout << "\nTotal Connected Components: " << componentCount << "\n";
}

int main() {
    int V = 7; // Number of vertices (0..V-1)
    vector<vector<int>> adj(V);

    // Lambda to add undirected edges
    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    // Example graph with 2 disconnected parts
    // Component 1: 0-1-2-3
    // Component 2: 4-5-6
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(4, 5);
    addEdge(5, 6);

    // Print adjacency list
    cout << "Adjacency List:\n";
    for (int i = 0; i < V; ++i) {
        cout << i << " -> ";
        for (int v : adj[i]) cout << v << " ";
        cout << "\n";
    }
    cout << "\n";

    // Find connected components
    findConnectedComponents(adj, V);

    return 0;
}
// Adjacency List:
// 0 -> 1 
// 1 -> 0 2 
// 2 -> 1 3 
// 3 -> 2 
// 4 -> 5 
// 5 -> 4 6 
// 6 -> 5 

// Component 1: 0 1 2 3 
// Component 2: 4 5 6 

// Total Connected Components: 2
