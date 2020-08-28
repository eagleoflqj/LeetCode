class Solution {
    vector<int> v1, ret;
    int i = 0, n;
    void helper1(TreeNode *root) {
        if(!root)
            return;
        helper1(root->left);
        v1.push_back(root->val);
        helper1(root->right);
    }
    void helper2(TreeNode *root) {
        if(!root)
            return;
        helper2(root->left);
        while(i < n && v1[i] <= root->val)
            ret.push_back(v1[i++]);
        ret.push_back(root->val);
        helper2(root->right);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        helper1(root1);
        n = v1.size();
        helper2(root2);
        while(i < n)
            ret.push_back(v1[i++]);
        return ret;
    }
};
