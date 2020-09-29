class Solution {
    int ret = 0;
    pair<int, int> helper(TreeNode *root) {
        int m = root->val, M = root->val;
        for(auto branch : {root->left, root->right})
            if(branch) {
                auto p = helper(branch);
                ret = max(max(abs(root->val - p.first), abs(root->val - p.second)), ret);
                m = min(p.first, m);
                M = max(p.second, M);
            }
        return {m, M};
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        helper(root);
        return ret;
    }
};
