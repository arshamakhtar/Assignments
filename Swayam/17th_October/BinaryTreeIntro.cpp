#include <bits/stdc++.h>
using namespace std;

// Node ka definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) {
        val = v;
        left = right = nullptr;
    }
};

int main() {
    // Example: simple tree
    //        1
    //       / \
    //      2   3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout << "Root value: " << root->val << endl;
    cout << "Left child: " << root->left->val << endl;
    cout << "Right child: " << root->right->val << endl;
}
