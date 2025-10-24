#include <bits/stdc++.h>
using namespace std;

// Node ka structure
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

// Level order input se binary tree build karna
Node* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return NULL;
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front(); q.pop();
        // left child
        if (arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;
        // right child
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Left leaves ka sum nikaalo (helper function)
int sumOfLeftLeaves(Node* root) {
    if (!root) return 0;
    int sum = 0;
    if (root->left && !root->left->left && !root->left->right)
        sum += root->left->val; // Agar left child leaf hai toh add karo
    sum += sumOfLeftLeaves(root->left);  // Recursively left ke liye call karo
    sum += sumOfLeftLeaves(root->right); // Recursively right ke liye call karo
    return sum;
}

int main() {
    int n;
    cin >> n; // Kitne elements (level order, -1 means NULL)
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* root = buildTree(arr);
    cout << sumOfLeftLeaves(root) << endl;
    return 0;
}
