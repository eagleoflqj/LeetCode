class Solution {
    static vector<signed char> regularize(const string &s) {
        vector<signed char> m(128, -1);
        char i = 0;
        vector<signed char> ret;
        for(char c : s) {
            if(m[c] < 0)
                m[c] = i++;
            ret.push_back(m[c]);
        }
        return ret;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        auto p = regularize(pattern);
        vector<string> ret;
        copy_if(words.begin(), words.end(), back_inserter(ret),
            [&p](const string &s) { return p == regularize(s); });
        return ret;
    }
};