class Solution {
    int ret = INT_MIN;
    int helper(TreeNode *root) {
        if(!root)
            return 0;
        int left = helper(root->left), right = helper(root->right), val = root->val;
        int M = val + max({0, left, right});
        ret = max({ret, M, val + left + right});
        return M;
    }
public:
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ret;
    }
};
