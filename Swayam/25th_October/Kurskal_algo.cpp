#include<bits/stdc++.h>
using namespace std;

/*
In Kruskal's algorithm, the initial spanning tree only contains the nodes of
the graph and does not contain any edges. Then the algorithm goes through the
edges ordered by their weights, and always adds an edge to the tree if it does not
create a cycle.
The algorithm maintains the components of the tree. Initially, each node of
the graph belongs to a separate component. Always when an edge is added to the
tree, two components are joined. Finally, all nodes belong to the same component,
and a minimum spanning tree has been found.
*/

/* IMPLIMENTATION */
// Union-Find (Disjoint Set Union - DSU) implementation
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    // Find representative of set containing x (with path compression)
    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    // Check if a and b are in the same component
    bool same(int a, int b) {
        return find(a) == find(b);
    }
    
    // Unite sets containing a and b
    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if(pa == pb) return;
        if(rank[pa] < rank[pb])
            parent[pa] = pb;
        else {
            parent[pb] = pa;
            if(rank[pa] == rank[pb])
                rank[pa]++;
        }
    }
};

int kruskalMST(int n, vector<vector<int>>& edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });
    
    DSU dsu(n);
    int mstWeight = 0;
    int edgesUsed = 0;
    
    // Process edges in ascending order of weight
    for(const auto& edge : edges) {
        int a = edge[0], b = edge[1], w = edge[2];
        if(!dsu.same(a, b)) {
            dsu.unite(a, b);
            mstWeight += w;
            edgesUsed++;
            cout << "Edge added: " << a << " - " << b << " : " << w << endl;
            if(edgesUsed == n-1) break; // MST complete
        }
    }
    return mstWeight;
}

// Example driver code
int main() {
    // Example graph: 4 nodes, edges: {node1, node2, weight}
    int n = 4;
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    
    int mstWeight = kruskalMST(n, edges);
    cout << "Minimum Spanning Tree Weight: " << mstWeight << endl;

    return 0;
}

// Output
// Edge added: 2 - 3 : 4
// Edge added: 0 - 3 : 5
// Edge added: 0 - 1 : 10
// Minimum Spanning Tree Weight: 19