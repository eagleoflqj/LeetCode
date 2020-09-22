class Solution {
    int ret = 0;
    int count[10]{};
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        ++count[root->val];
        if(!(root->left || root->right)) {
            int odd = 0;
            for(int i = 1; i < 10; ++i)
                if(count[i] & 1)
                    ++odd;
            if(odd <= 1)
                ++ret;
        } else {
            if(root->left)
                pseudoPalindromicPaths(root->left);
            if(root->right)
                pseudoPalindromicPaths(root->right);
        }
        --count[root->val];
        return ret;
    }
};
