class Solution {
public:
    string removeOuterParentheses(string S) {
        string ret;
        int count = 0;
        for(auto c : S) {
            if(c == '(') {
                ++count;
                if(count > 1)
                    ret += c;
            } else {
                --count;
                if(count > 0)
                    ret += c;
            }
        }
        return ret;
    }
};
