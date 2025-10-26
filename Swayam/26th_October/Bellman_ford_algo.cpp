#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        // Distance array initialize karo, saare ko infinity set karo
        vector<int> dist(V, INT_MAX);
        dist[src] = 0; // Source ka distance 0 set karo

        // V-1 baar relax karo saare edges ko
        // Kyunki shortest path mein maximum V-1 edges ho sakte hain
        for (int i = 0; i < V - 1; i++)
        {
            for (auto &edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                // Agar u tak path hai aur v ka distance reduce ho sakta hai
                if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt; // Distance update karo
                }
            }
        }

        // Negative cycle check karo
        // Agar koi distance ab bhi reduce hota hai toh negative cycle hai
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            {
                cout << "Negative cycle detected!" << endl;
                return {}; // Empty array return karo
            }
        }

        return dist;
    }
};

// Driver code
int main()
{
    Solution sol;

    // Graph: V = 5 vertices
    // Edges: {u, v, weight} format mein
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 11},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, 13}};

    int source = 0;
    vector<int> distances = sol.bellmanFord(V, edges, source);

    // Print the distances
    if (!distances.empty())
    {
        cout << "Shortest distances from source " << source << ":" << endl;
        for (int i = 0; i < V; i++)
        {
            if (distances[i] == INT_MAX)
                cout << "Node " << i << ": INF" << endl;
            else
                cout << "Node " << i << ": " << distances[i] << endl;
        }
    }

    return 0;
}

// output:
// Shortest distances from source 0:
// Node 0: 0
// Node 1: 11
// Node 2: 4
// Node 3: 13
// Node 4: 13
