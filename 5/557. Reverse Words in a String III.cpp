class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), b;
        bool status = false;
        auto beg = s.begin();
        for(int i = 0; i <= n; ++i) {
            if(isspace(s[i]) || !s[i]) {
                if(status) {
                    status = false;
                    reverse(beg + b, beg + i);
                }
            } else if(!status) {
                status = true;
                b = i;
            }
        }
        return s;
    }
};
