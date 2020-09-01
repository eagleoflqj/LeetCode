class Solution {
public:
    bool isValid(string s) {
        static const char *parentheses[]{"()", "[]", "{}"};
        stack<char> stk;
        for(char c : s)
            for(auto p : parentheses)
                if(c == p[0]) {
                    stk.push(c);
                    break;
                } else if(c == p[1]) {
                    if(stk.empty() || stk.top() != p[0])
                        return false;
                    stk.pop();
                    break;
                }
        return stk.empty();
    }
};
