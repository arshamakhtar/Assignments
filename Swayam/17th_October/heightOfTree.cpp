#include<bits/stdc++.h>
using namespace std;

//build tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) {
        val = v;
        left = right = nullptr;
    }
};


int height(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int main(){

    TreeNode* node= new TreeNode(1);
    node -> right= new TreeNode(2);
    node -> left = new TreeNode(3);
    node -> left -> left = new TreeNode(6);
    node -> right->right = new TreeNode(4);
    node-> left -> left->right = new TreeNode(5);
    node->left -> right = new TreeNode(6);

    cout<<"Height of tree: "<<endl;
    cout<<height(node)<<endl;
    return 0;
}