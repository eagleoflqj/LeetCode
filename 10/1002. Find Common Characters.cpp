class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> count(26, INT_MAX);
        for(const string &s : A) {
            int s_count[26]{};
            for(char c : s)
                ++s_count[c - 'a'];
            for(int i = 0; i < 26; ++i)
                count[i] = min(count[i], s_count[i]);
        }
        vector<string> ret;
        string s("a");
        for(int i = 0; i < 26; ++i) {
            for(int j = 0; j < count[i]; ++j)
                ret.push_back(s);
            ++s[0];
        }
        return ret;
    }
};
