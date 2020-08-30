class FindElements {
    unordered_set<int> m;
    void recover(TreeNode *root, int x) {
        root->val = x;
        m.insert(x);
        if(root->left)
            recover(root->left, (x << 1) + 1);
        if(root->right)
            recover(root->right, (x << 1) + 2);
    }
public:
    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    bool find(int target) {
        return m.find(target) != m.end();
    }
};
