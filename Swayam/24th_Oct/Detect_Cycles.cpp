#include <iostream>
#include <vector>
using namespace std;

// Helper function to perform DFS and detect cycle.
// 'v' is the current node being visited.
// 'parent' is the previous node in DFS (to avoid false cycle detection).
bool dfsCycle(int v, const vector<vector<int>> &adj, vector<bool> &visited, int parent) {
    visited[v] = true; // Mark current node as visited.

    for (int neighbor : adj[v]) {
        // If neighbor is not visited, recurse and check for a cycle.
        if (!visited[neighbor]) {
            if (dfsCycle(neighbor, adj, visited, v))
                return true; // Cycle found in recursion.
        }
        // If neighbor is visited and not the parent, then there is a cycle.
        else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

// Main function to check whether the undirected graph contains a cycle.
bool hasCycle(int V, const vector<vector<int>> &adj) {
    vector<bool> visited(V, false);

    // Handle disconnected graphs: try DFS from every unvisited node.
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsCycle(i, adj, visited, -1))
                return true; // Cycle detected.
        }
    }
    return false; // No cycle found in any component.
}

// Example usage:
int main() {
    int V = 3;
    // Adjacency list representation of the graph.
    // Example graph: 0-1, 1-2, 2-0 (cycle exists)
    vector<vector<int>> adj = {
        {1, 2}, // Node 0 connected to 1,2
        {0, 2}, // Node 1 connected to 0,2
        {0, 1}  // Node 2 connected to 0,1
    };

    if (hasCycle(V, adj))
        cout << "Cycle detected in the graph.\n";
    else
        cout << "No cycle found in the graph.\n";

    return 0;
}
