#include <bits/stdc++.h>
using namespace std;

// DP approach: n nodes se kitne unique BST ban sakte hain (Catalan numbers)
int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int nodes = 2; nodes <= n; nodes++) {
        for (int root = 1; root <= nodes; root++) {
            // left subtree * right subtree
            dp[nodes] += dp[root - 1] * dp[nodes - root];
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n; // Input node count lo
    cout << numTrees(n) << endl; // Unique BSTs print karo
    return 0;
}
