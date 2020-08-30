class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode **current = &root;
        while(*current)
            current = &(val < (*current)->val ? (*current)->left : (*current)->right);
        *current = new TreeNode(val);
        return root;
    }
};
