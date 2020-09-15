class Solution {
public:
    int lengthOfLastWord(string s) {
        string ret;
        int e = s.size(), b;
        while(e > 0 && s[e - 1] == ' ')
            --e;
        for(b = e; b > 0 && s[b - 1] != ' '; --b);
        return e - b;
    }
};
