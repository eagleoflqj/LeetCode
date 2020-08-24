class Solution {
public:
    int balancedStringSplit(string s) {
        int r = 0, ret = 0;
        for(auto c : s)
            if((c == 'R' && !++r) || (c == 'L' && !--r))
                ++ret;
        return ret;
    }
};
