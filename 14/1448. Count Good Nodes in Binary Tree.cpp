class Solution {
    int helper(TreeNode *root, int M) {
        if(!root)
            return 0;
        int good = root->val >= M;
        if(good)
            M = root->val;
        return good + helper(root->left, M) + helper(root->right, M);
    }
public:
    int goodNodes(TreeNode* root) {
        return helper(root, INT_MIN);
    }
};
