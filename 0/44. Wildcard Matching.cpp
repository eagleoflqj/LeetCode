/*
 ababc
 | \?    2nd * fails to match, no need to traceback to 1st *
*a* bc
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int s_size = s.size();
        int p_size = p.size();
        int i = 0, j = 0, i_star = -1, j_star = -1;
        while(i <= s_size && j <= p_size) { // include '\0'
            if(p[j] == '?' || s[i] == p[j]) {
                ++i; ++j;
            } else if(p[j] == '*') {
                i_star = i; // last match * until s[i]
                j_star = ++j; // last * occurs at p[j_star - 1]
            } else if(i_star >= 0) { // mismatch, traceback
                i = ++i_star; // * match one more char
                j = j_star; // the position after *
            } else
                return false;
        }
        return i > s_size && j > p_size;
    }
};
