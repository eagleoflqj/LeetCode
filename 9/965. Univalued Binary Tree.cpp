class Solution {
    bool helper(TreeNode *root, int val) {
        return !root || (root->val == val && helper(root->left, val) && helper(root->right, val));
    }
public:
    bool isUnivalTree(TreeNode* root) {
        return helper(root, root->val);
    }
};
