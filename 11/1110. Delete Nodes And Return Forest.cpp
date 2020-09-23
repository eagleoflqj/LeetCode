class Solution {
    vector<TreeNode*> ret;
    unordered_set<int> st;
    void helper(TreeNode **root, bool hasParent) {
        TreeNode *node = *root;
        if(!node)
            return;
        if(st.find(node->val) == st.end()) {
            if(!hasParent) {
                ret.push_back(node);
                hasParent = true;
            }
        } else {
            *root = nullptr;
            hasParent = false;
        }
        helper(&node->left, hasParent);
        helper(&node->right, hasParent);
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i : to_delete)
            st.insert(i);
        helper(&root, false);
        return ret;
    }
};
