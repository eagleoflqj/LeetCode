class Solution {
    int level = 0;
    vector<int> sum;
public:
    int maxLevelSum(TreeNode* root) {
        ++level;
        if(sum.size() < level)
            sum.push_back(root->val);
        else
            sum[level - 1] += root->val;
        if(root->left)
            maxLevelSum(root->left);
        if(root->right)
            maxLevelSum(root->right);
        if(--level)
            return 0;
        return max_element(sum.begin(), sum.end()) - sum.begin() + 1;
    }
};
