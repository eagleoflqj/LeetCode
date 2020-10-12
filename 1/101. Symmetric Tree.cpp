class Solution {
    bool helper(TreeNode *left, TreeNode *right) {
        if(!left && !right)
            return true;
        if(left && right && left->val == right->val)
            return helper(left->left, right->right) && helper(right->left, left->right);
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return root ? helper(root->left, root->right) : true;
    }
};
