class Solution {
    int helper(TreeNode *root, bool odd_parent, bool odd_grandparent) {
        int ret = odd_grandparent ? 0 : root->val;
        bool odd = (root->val) & 1;
        if(root->left)
            ret += helper(root->left, odd, odd_parent);
        if(root->right)
            ret += helper(root->right, odd, odd_parent);
        return ret;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        return helper(root, true, true);
    }
};
