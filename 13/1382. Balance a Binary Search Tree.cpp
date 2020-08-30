class Solution {
    vector<TreeNode *> v;
    TreeNode *convertToList(TreeNode *root, TreeNode *pmax) {
        root->right = root->right ? convertToList(root->right, pmax) : pmax;
        return root->left ? convertToList(root->left, root) : root;
    }
    TreeNode *convertToBST(int b, int e) {
        if(e == b)
            return nullptr;
        int m = (b + e) >> 1;
        v[m]->left = convertToBST(b, m);
        v[m]->right = convertToBST(m + 1, e);
        return v[m];
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        TreeNode *l = convertToList(root, nullptr);
        do {
            v.push_back(l);
        } while((l = l->right));
        return convertToBST(0, v.size());
    }
};
