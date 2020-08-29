namespace {
    constexpr int UB = 20;
}

class Solution {
    static TreeNode *clone(TreeNode *root) {
        return root ? new TreeNode(root->val, clone(root->left), clone(root->right)) : nullptr;
    }
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        static vector<TreeNode*> dictionary[UB + 1]{{}, {new TreeNode}};
        if(!(N & 1))
            return dictionary[0];
        if(dictionary[N].empty())
            for(int i = 1; i < N; i += 2)
                for(auto left : allPossibleFBT(i))
                    for(auto right : allPossibleFBT(N - 1 - i))
                        dictionary[N].push_back(new TreeNode(0, clone(left), clone(right)));
        return dictionary[N];
    }
};
