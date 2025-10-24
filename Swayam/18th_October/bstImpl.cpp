struct BSTNode {
    int val;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int v): val(v), left(nullptr), right(nullptr) {}
};

BSTNode* insert(BSTNode* root, int val) {
    if (!root) return new BSTNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void inorder(BSTNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    BSTNode* root = nullptr;
    vector<int> vals = {5, 3, 7, 2, 4, 6, 8};
    for (int v : vals) root = insert(root, v);

    inorder(root); // BST inorder sorted output
}
