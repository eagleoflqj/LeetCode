class Solution {
    int ret = 0;
    int current = 0;
    void helper(TreeNode *root) {
        current = (current << 1) | root->val;
        if(!(root->left || root->right))
            ret += current;
        else {
            if(root->left)
                helper(root->left);
            if(root->right)
                helper(root->right);
        }
        current >>= 1;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        helper(root);
        return ret;
    }
};
