bool isValidBST(BSTNode* root, long minV = LONG_MIN, long maxV = LONG_MAX) {
    if (!root) return true;
    if (root->val <= minV || root->val >= maxV) return false;
    return isValidBST(root->left, minV, root->val) && isValidBST(root->right, root->val, maxV);
}
