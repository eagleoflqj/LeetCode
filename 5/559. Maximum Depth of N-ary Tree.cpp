class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        int ret = 0;
        for(Node *child : root->children)
            ret = max(ret, maxDepth(child));
        return ret + 1;
    }
};
