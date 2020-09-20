class Solution {
    struct group{
        enum{left, valid} type;
        int count;
    };
public:
    int longestValidParentheses(string s) {
        stack<group> stk;
        int ret = 0;
        for(auto c : s) {
            if(c == '(') {
                if(stk.empty() || stk.top().type == group::valid)
                    stk.push({group::left, 1});
                else
                    ++stk.top().count;
            } else if(!stk.empty()) {
                int length = 0;
                if(stk.top().type == group::valid) {
                    length = stk.top().count;
                    stk.pop();
                    if(stk.empty())
                        continue;
                }
                length += 2;
                if(stk.top().count > 1) {
                    --stk.top().count;
                    stk.push({group::valid, length});
                } else {
                    stk.pop();
                    if(!stk.empty()) {
                        length += stk.top().count;
                        stk.top().count = length;
                    } else
                        stk.push({group::valid, length});
                }
                ret = max(ret, length);
            }
        }
        return ret;
    }
};
