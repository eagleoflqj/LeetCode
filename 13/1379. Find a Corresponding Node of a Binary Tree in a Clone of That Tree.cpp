class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == target)
            return cloned;
        TreeNode *ret;
        if(original->left && (ret = getTargetCopy(original->left, cloned->left, target)))
            return ret;
        if(original->right && (ret = getTargetCopy(original->right, cloned->right, target)))
            return ret;
        return nullptr;
    }
};
