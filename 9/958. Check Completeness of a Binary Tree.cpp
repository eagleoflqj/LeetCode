class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 1);
        int n = 1;
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            if(p.first->left) {
                ++n;
                if(p.second << 1 != n)
                   return false;
                q.emplace(p.first->left, n);
            }
            if(p.first->right) {
                ++n;
                if((p.second << 1) + 1 != n)
                    return false;
                q.emplace(p.first->right, n);
            }
        }
        return true;
    }
};
