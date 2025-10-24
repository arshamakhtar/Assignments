#include <bits/stdc++.h>
using namespace std;

//There are two main Methods to represent a graph in DSA

/*
In the adjacency list representation, each node x in the graph is assigned an
adjacency list that consists of nodes to which there is an edge from x. Adjacency
lists are the most popular way to represent graphs, and most algorithms can be
efficiently implemented using them.
*/


int main() {
    int V = 5; // number of vertices (0..V-1)
    vector<vector<int>> adj(V);
    
    //Adding each Edge into List 
    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    };

    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);

    // print adjacency list
    for (int u = 0; u < V; ++u) {
        cout << u << ":";
        for (int v : adj[u]) cout << " " << v;
        cout << '\n';
    }
    return 0;
}
// Adjacency List Representation of the Graph:
// ----------------------------------------------
// 0: 1 4
// 1: 0 2 3 4
// 2: 1 3
// 3: 1 2 4
// 4: 0 1 3
