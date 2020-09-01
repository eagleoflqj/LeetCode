class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if(!n)
            return ret;
        stack<int> stk;
        stk.push(0);
        string s((n << 1) + 1, 0);
        while(!stk.empty()) {
            int length = stk.size() - 1;
            if(length == n << 1) {
                ret.push_back(s);
                s[length] = 0;
                stk.pop();
                continue;
            }
            int left_count = stk.top();
            if(!s[length] && left_count < n) {
                s[length] = '(';
                stk.push(left_count + 1);
            } else if(s[length] == ')') {
                s[length] = 0;
                stk.pop();
            } else {
                s[length] = ')';
                if(left_count > length - left_count)
                    stk.push(left_count);
            }
        }
        return ret;
    }
};
