class Solution {
    int ret = 0;
    int helper(TreeNode *root) {
        if(!root)
            return 0;
        int val = helper(root->left) + helper(root->right) + root->val - 1;
        ret += abs(val);
        return val;
    }
public:
    int distributeCoins(TreeNode* root) {
        helper(root);
        return ret;
    }
};
