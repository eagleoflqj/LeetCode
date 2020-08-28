class Solution {
    int helper(TreeNode *root, int sum) {
        if(root->right)
            sum = helper(root->right, sum);
        sum = root->val += sum;
        if(root->left)
            sum = helper(root->left, sum);
        return sum;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        helper(root, 0);
        return root;
    }
};
