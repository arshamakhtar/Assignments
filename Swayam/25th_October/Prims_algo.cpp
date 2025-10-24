#include <bits/stdc++.h>
using namespace std;

// Like Dijkstra’s algorithm, Prim’s algorithm can be efficiently implemented using a
// priority queue. The priority queue should contain all nodes that can be connected
// to the current component using a single edge, in increasing order of the weights
// of the corresponding edges.
// The time complexity of Prim’s algorithm is O(n+ m log m) that equals the time
// complexity of Dijkstra’s algorithm.

class Solution {
public:
    int primMST(int n, vector<vector<pair<int, int>>>& adj) {
        // Priority queue: {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<bool> inMST(n, false);
        int mstWeight = 0;
        int edgesUsed = 0;
        
        // Start from node 0
        pq.push({0, 0});
        
        cout << "Edges in MST:" << endl;
        
        while (!pq.empty() && edgesUsed < n) {
            auto [weight, u] = pq.top();
            pq.pop();
            
            // Skip if already in MST
            if (inMST[u]) continue;
            
            // Add to MST
            inMST[u] = true;
            mstWeight += weight;
            edgesUsed++;
            
            if (weight > 0) {  // Don't print starting node
                cout << "Node " << u << " added with weight " << weight << endl;
            }
            
            // Add all adjacent edges to priority queue
            for (auto [v, w] : adj[u]) {
                if (!inMST[v]) {
                    pq.push({w, v});
                }
            }
        }
        
        return mstWeight;
    }
};

// Driver code
int main() {
    Solution sol;
    
    // Graph with 4 nodes
    int n = 4;
    vector<vector<pair<int, int>>> adj(n);
    
    // Add edges: adj[u] = {{v, weight}, ...}
    adj[0].push_back({1, 10});
    adj[0].push_back({2, 6});
    adj[0].push_back({3, 5});
    
    adj[1].push_back({0, 10});
    adj[1].push_back({3, 15});
    
    adj[2].push_back({0, 6});
    adj[2].push_back({3, 4});
    
    adj[3].push_back({0, 5});
    adj[3].push_back({1, 15});
    adj[3].push_back({2, 4});
    
    int mstWeight = sol.primMST(n, adj);
    cout << "\nTotal MST Weight: " << mstWeight << endl;
    // Output: 19
    
    return 0;
}

// Output:
// Edges in MST:
// Node 3 added with weight 5
// Node 2 added with weight 4
// Node 1 added with weight 10

// Total MST Weight: 19
