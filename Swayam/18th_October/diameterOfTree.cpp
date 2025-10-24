#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

class Solution {
    int ans = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int leftH = dfs(root->left);
        int rightH = dfs(root->right);
        ans = max(ans, leftH + rightH); // diameter = left height + right height
        return 1 + max(leftH, rightH);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << sol.diameterOfBinaryTree(root);
}
