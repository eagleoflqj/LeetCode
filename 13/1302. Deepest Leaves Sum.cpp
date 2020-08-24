class Solution {
public:
    int max_depth = 0;
    int ret = 0;
    void helper(const TreeNode *root, int depth) {
        const TreeNode *left = root->left, *right = root->right;
        if(!left && !right) {
            if(depth > max_depth) {
                max_depth = depth;
                ret = root->val;
            } else if(depth == max_depth)
                ret += root->val;
            return;
        }
        if(left)
            helper(left, depth + 1);
        if(right)
            helper(right, depth + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        helper(root, 0);
        return ret;
    }
};
