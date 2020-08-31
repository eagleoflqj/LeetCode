class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ret;
        if(!root)
            return ret;
        stack<pair<Node*, bool>> stk;
        stk.emplace(root, false);
        while(!stk.empty()) {
            auto &p = stk.top();
            if(p.second) {
                ret.push_back(p.first->val);
                stk.pop();
                continue;
            }
            p.second = true;
            const auto &children = p.first->children;
            for(auto rb = children.rbegin(), re = children.rend(); rb != re; ++rb)
                stk.emplace(*rb, false);
        }
        return ret;
    }
};
