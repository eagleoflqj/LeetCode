class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0;
        int ret = 0;
        for(char c : S)
            if(c == '(')
                ++left;
            else if(!left)
                ++ret;
            else
                --left;
        return ret + left;
    }
};
