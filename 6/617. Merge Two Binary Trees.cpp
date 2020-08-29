class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode empty;
        if(!(t1 || t2))
            return nullptr;
        if(!t1)
            t1 = &empty;
        else if(!t2)
            t2 = &empty;
        return new TreeNode(t1->val + t2->val, mergeTrees(t1->left, t2->left), mergeTrees(t1->right, t2->right));
    }
};
