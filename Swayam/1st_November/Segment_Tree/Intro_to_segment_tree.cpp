#include <bits/stdc++.h>
using namespace std;

/*
 * Segment Tree Implementation
 * This is a data structure that allows us to perform range queries and updates efficiently
 * Time Complexity:
 * - Build: O(n)
 * - Query: O(log n)
 * - Update: O(log n)
 * Space Complexity: O(n)
 */

class SegmentTree {
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    // Helper function to build the segment tree
    void build(int node, int start, int end) {
        if (start == end) {
            // Leaf node will have a single element
            tree[node] = arr[start];
            return;
        }
        
        int mid = (start + end) / 2;
        
        // Recursively build left and right subtrees
        build(2 * node + 1, start, mid);       // Left child
        build(2 * node + 2, mid + 1, end);     // Right child
        
        // Internal node will have the sum of both of its children
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // Helper function for range query
    int query(int node, int start, int end, int l, int r) {
        if (l > end || r < start)    // Range completely outside
            return 0;
        
        if (l <= start && r >= end)  // Range completely inside
            return tree[node];
        
        int mid = (start + end) / 2;
        int leftSum = query(2 * node + 1, start, mid, l, r);
        int rightSum = query(2 * node + 2, mid + 1, end, l, r);
        
        return leftSum + rightSum;
    }

    // Helper function for point update
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
    SegmentTree(vector<int>& input) {
        arr = input;
        n = input.size();
        // Maximum size needed for segment tree array is 4n
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    // Get sum of range [l, r]
    int getSum(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    // Update value at index idx
    void update(int idx, int val) {
        updateHelper(0, 0, n - 1, idx, val);
    }
};

int main() {
    // Example usage
    vector<int> arr = {3, 8, 7, 6, 2, -8, 4, 9};
    //                 0  1  2  3  4   5  6  7
    
    // Create segment tree
    SegmentTree segTree(arr);
    
    // Example queries
    cout << "Sum of range [1, 3]: " << segTree.getSum(1, 3) << endl;  // Should print 21 (8 + 7 + 6)
    
    // Update value at index 2 to 10
    segTree.update(2, 10);
    
    // Query after update
    cout << "Sum of range [1, 3] after update: " << segTree.getSum(1, 3) << endl;  // Should print 24 (8 + 10 + 6)
    
    return 0;
}