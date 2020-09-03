class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(0, (s.size() << 1) - 1).find(s, 1) != string::npos;
    }
};
