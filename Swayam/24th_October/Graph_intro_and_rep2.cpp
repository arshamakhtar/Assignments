#include <bits/stdc++.h>
using namespace std;

/*
An adjacency matrix is a two-dimensional array that indicates which edges
the graph contains. We can efficiently check from an adjacency matrix if there is
an edge between two nodes. The matrix can be stored as an array

lets say an int adj[N][N] where N is the number of nodes
*/

/*    Vertices = {0, 1, 2, 3, 4}
    Edges = {
        {0,1}, {0,4}, {1,2}, {1,3}, {1,4}, {2,3}, {3,4}
    }
*/

int main() {
    int V = 5; // Number of vertices (0..V-1)

    // Initialize a VxV matrix with 0 (no edges)
    vector<vector<int>> adj(V, vector<int>(V, 0));

    // Lambda function to add an edge
    auto addEdge = [&](int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graphs
    };

    // Build the graph
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);

    // Print the Adjacency Matrix
    cout << "ADJACENCY MATRIX REPRESENTATION\n";
    cout << "---------------------------------\n\n";

    // Print column headers
    cout << "    ";
    for (int j = 0; j < V; ++j) cout << j << " ";
    cout << "\n";

    cout << "    ";
    for (int j = 0; j < V; ++j) cout << "--";
    cout << "\n";

    // Print matrix with row labels
    for (int i = 0; i < V; ++i) {
        cout << i << " | ";
        for (int j = 0; j < V; ++j)
            cout << adj[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
// ADJACENCY MATRIX REPRESENTATION
// ---------------------------------

//     0 1 2 3 4 
//     ----------
// 0 | 0 1 0 0 1 
// 1 | 1 0 1 1 1 
// 2 | 0 1 0 1 0 
// 3 | 0 1 1 0 1 
// 4 | 1 1 0 1 0 
