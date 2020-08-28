class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> stk;
        for(auto i : nums) {
            TreeNode *node = new TreeNode(i), *left = nullptr;
            while(!stk.empty() && stk.top()->val < i) {
                stk.top()->right = left;
                left = stk.top();
                stk.pop();
            }
            node->left = left;
            stk.push(node);
        }
        TreeNode *right = nullptr;
        do {
            stk.top()->right = right;
            right = stk.top();
            stk.pop();
        } while(!stk.empty());
        return right;
    }
};
