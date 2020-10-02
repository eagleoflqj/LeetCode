class Solution {
public:
    bool isValidBST(TreeNode* root, int64_t *m = nullptr, int64_t *M = nullptr) {
        if(!root)
            return true;
        int64_t m_left = root->val, M_left = INT_MIN - 1LL, m_right = INT_MAX + 1LL, M_right = root->val;
        if(!(isValidBST(root->left, &m_left, &M_left) && isValidBST(root->right, &m_right, &M_right)))
            return false;
        if(M_left >= root->val || m_right <= root->val)
            return false;
        if(m) {
            *m = m_left;
            *M = M_right;
        }
        return true;
    }
};
