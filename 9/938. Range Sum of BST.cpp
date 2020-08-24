class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root)
            return 0;
        int ret = 0;
        int val = root->val;
        if(L <= val && val <= R)
            ret = val;
        if(val < R)
            ret += rangeSumBST(root->right, L, R);
        if(val > L)
            ret += rangeSumBST(root->left, L, R);
        return ret;
    }
};
