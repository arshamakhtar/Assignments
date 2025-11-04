#include <bits/stdc++.h>
using namespace std;

/*
 * Prefix Sum Segment Tree Implementation
 * This implementation focuses on prefix sum queries [0, r] and point updates
 * A prefix sum query asks for the sum of all elements from index 0 to r
 * 
 * Time Complexity:
 * - Build: O(n)
 * - Prefix Sum Query: O(log n)
 * - Update: O(log n)
 * Space Complexity: O(n)
 */

class PrefixSumTree {
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // Helper function to get prefix sum up to index r
    int getPrefixSum(int node, int start, int end, int r) {
        // If the range is completely outside
        if (r < start)
            return 0;
        
        // If the range is completely inside (meaning we need the whole sum of this segment)
        if (r >= end)
            return tree[node];
        
        int mid = (start + end) / 2;
        int leftSum = getPrefixSum(2 * node + 1, start, mid, r);
        int rightSum = getPrefixSum(2 * node + 2, mid + 1, end, min(r, end));
        
        return leftSum + rightSum;
    }

    void updateHelper(int node, int start, int end, int idx, int val) {
        if (start == end) {
            arr[idx] = val;
            tree[node] = val;
            return;
        }
        
        int mid = (start + end) / 2;
        if (idx <= mid)
            updateHelper(2 * node + 1, start, mid, idx, val);
        else
            updateHelper(2 * node + 2, mid + 1, end, idx, val);
        
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

public:
    PrefixSumTree(vector<int>& input) {
        arr = input;
        n = input.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    // Get sum of all elements from index 0 to r (inclusive)
    int prefixSum(int r) {
        if (r < 0 || r >= n)
            return 0;
        return getPrefixSum(0, 0, n - 1, r);
    }

    // Update value at index idx
    void update(int idx, int val) {
        if (idx < 0 || idx >= n)
            return;
        updateHelper(0, 0, n - 1, idx, val);
    }

    // Get sum between two indices l and r
    int rangeSum(int l, int r) {
        if (l > r || l < 0 || r >= n)
            return 0;
        if (l == 0)
            return prefixSum(r);
        return prefixSum(r) - prefixSum(l - 1);
    }
};

int main() {
    // Example usage
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    //                 0  1  2  3  4  5
    
    PrefixSumTree prefixTree(arr);
    
    // Example prefix sum queries
    cout << "Prefix sum up to index 3: " << prefixTree.prefixSum(3) << endl;  // Should print 16 (1 + 3 + 5 + 7)
    cout << "Prefix sum up to index 5: " << prefixTree.prefixSum(5) << endl;  // Should print 36 (1 + 3 + 5 + 7 + 9 + 11)
    
    // Example range sum query
    cout << "Sum of range [2, 4]: " << prefixTree.rangeSum(2, 4) << endl;  // Should print 21 (5 + 7 + 9)
    
    // Update value at index 2 to 10
    prefixTree.update(2, 10);
    
    // Query after update
    cout << "Prefix sum up to index 3 after update: " << prefixTree.prefixSum(3) << endl;  // Should print 21 (1 + 3 + 10 + 7)
    cout << "Sum of range [2, 4] after update: " << prefixTree.rangeSum(2, 4) << endl;  // Should print 26 (10 + 7 + 9)
    
    return 0;
}