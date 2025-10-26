#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
/*
Dijkstra's algorithm finds shortest paths from the starting node to all nodes of
the graph, like the Bellman-Ford algorithm. The benefit of Dijsktra's algorithm
is that it is more efficient and can be used for processing large graphs. However,
the algorithm requires that there are no negative weight edges in the graph
*/

// At each step, Dijkstra’s algorithm selects a node that has not been processed
// yet and whose distance is as small as possible
class Solution {
public:
    vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& adj, int x) {
        // INITIALIZATION BLOCK
        // Set up distance array with infinity for all nodes, processed array to track visited nodes
        vector<int> distance(n + 1, INF);
        vector<bool> processed(n + 1, false);
        priority_queue<pair<int, int>> q;  // Max-heap, so we use negative distances
        
        distance[x] = 0;
        q.push({0, x});
        
        // MAIN DIJKSTRA LOOP
        // Process nodes in order of shortest distance from source
        while (!q.empty()) {
            int a = q.top().second;
            q.pop();
            
            // Skip if already processed (handles duplicates in queue)
            if (processed[a]) continue;
            processed[a] = true;
            
            // EDGE RELAXATION BLOCK
            // Check all neighbors and update their distances if shorter path found
            for (auto u : adj[a]) {
                int b = u.first, w = u.second;
                if (distance[a] + w < distance[b]) {
                    distance[b] = distance[a] + w;
                    q.push({-distance[b], b});
                }
            }
        }
        
        return distance;
    }
};

// Driver code
int main() {
    Solution sol;
    
    int n = 5;
    vector<vector<pair<int, int>>> adj(n + 1);
    
    // Build graph
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 5});
    adj[2].push_back({3, 4});
    adj[2].push_back({4, 4});
    adj[3].push_back({4, 3});
    adj[3].push_back({5, 1});
    adj[4].push_back({5, 2});
    
    int source = 1;
    vector<int> distances = sol.dijkstra(n, adj, source);
    
    // Display results
    cout << "Shortest distances from node " << source << ":" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << ": " << (distances[i] == INF ? "INF" : to_string(distances[i])) << endl;
    }
    
    return 0;
}
// Output:
// Shortest distances from node 1:
// Node 1: 0
// Node 2: 2
// Node 3: 5
// Node 4: 6
// Node 5: 6