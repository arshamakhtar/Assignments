#include <bits/stdc++.h>
using namespace std;

// Node ka structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

// Array se binary tree build karo (level order)
Node* buildTree(vector<int>& arr) {
    if (arr.empty()) return NULL;
    vector<Node*> nodes;
    for (int val : arr) nodes.push_back(val == -1 ? NULL : new Node(val));

    int n = arr.size();
    int i = 0, j = 1;
    while (j < n) {
        if (nodes[i]) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        } else {
            j += 2;
        }
        i++;
    }
    return nodes[0];
}

// Total nodes count karo
int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Tree complete hai ya nahi check karo
bool isComplete(Node* root, int index, int total) {
    if (!root) return true;
    if (index >= total) return false;
    return isComplete(root->left, 2 * index + 1, total) &&
           isComplete(root->right, 2 * index + 2, total);
}

// Heap property hai ya nahi check karo (max-heap)
bool isHeap(Node* root) {
    // Leaf node
    if (!root->left && !root->right) return true;
    // Sirf left child
    if (root->left && !root->right)
        return (root->data >= root->left->data) && isHeap(root->left);
    // Dono child
    if (root->left && root->right)
        return (root->data >= root->left->data) &&
               (root->data >= root->right->data) &&
               isHeap(root->left) && isHeap(root->right);
    // right child only (not possible in complete binary tree)
    return false;
}

int main() {
    int n;
    cin >> n; // Kitne nodes (level order input including -1 for NULL)
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* root = buildTree(arr);

    int total = countNodes(root);
    // Complete binary tree and heap dono check karo
    if (isComplete(root, 0, total) && isHeap(root))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
