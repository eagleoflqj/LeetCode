class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ret;
        if(!root)
            return ret;
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty()) {
            Node *node = stk.top();
            ret.push_back(node->val);
            stk.pop();
            for(auto rb = node->children.rbegin(); rb != node->children.rend(); ++rb)
                stk.push(*rb);
        }
        return ret;
    }
};
