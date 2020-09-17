class Solution {
public:
    TreeNode* increasingBST(TreeNode* root, TreeNode *tail = nullptr) {
        TreeNode *ret = root;
        if(root->left) {
            ret = increasingBST(root->left, root);
            root->left = nullptr;
        }
        if(root->right)
            root->right = increasingBST(root->right, tail);
        else
            root->right = tail;
        return ret;
    }
};
