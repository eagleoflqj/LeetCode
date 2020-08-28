class Solution {
    vector<int>::iterator b, e;
    TreeNode *helper(int ub) {
        int val = *b++;
        TreeNode *node = new TreeNode(val);
        if(b == e)
            return node;
        if(*b < val)
            node->left = helper(val);
        if(b < e && *b < ub)
            node->right = helper(ub);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        b = preorder.begin();
        e = preorder.end();
        return helper(1e8 + 1);
    }
};
