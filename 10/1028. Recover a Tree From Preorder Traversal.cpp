class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        int i = 0, n = S.size();
        vector<TreeNode*> v;
        while(i < n) {
            int depth = 0;
            while(S[i] == '-') {
                ++depth;
                ++i;
            }
            int val = 0;
            do {
                val = val * 10 + S[i] - '0';
            } while(++i < n && isdigit(S[i]));
            TreeNode *node = new TreeNode(val);
            if(depth == v.size()) {
                if(!v.empty())
                    v.back()->left = node; 
            } else {
                do {
                    v.pop_back();
                } while(depth < v.size());
                v.back()->right = node;
            }
            v.push_back(node);
        }
        return v[0];
    }
};
