class Solution {
    pair<TreeNode*, int> helper(TreeNode *root) {
        if(!root)
            return {nullptr, 0};
        auto left = helper(root->left), right = helper(root->right);
        if(!(left.first || right.first))
            return {root, 1};
        if(left.second < right.second)
            return {right.first, right.second + 1};
        if(left.second > right.second)
            return {left.first, left.second + 1};
        return {root, left.second + 1};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).first;
    }
};
