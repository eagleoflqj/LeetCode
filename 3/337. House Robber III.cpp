class Solution {
    pair<int, int> helper(TreeNode *root) {
        if(!root)
            return {0, 0};
        auto left = helper(root->left), right = helper(root->right);
        return {root->val + left.second + right.second, max(left.first, left.second) + max(right.first, right.second)};
    }
public:
    int rob(TreeNode* root) {
        auto ret = helper(root);
        return max(ret.first, ret.second);
    }
};
