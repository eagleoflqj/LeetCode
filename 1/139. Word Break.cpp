class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> breakable(n + 1);
        breakable[n] = true;
        for(int i = n - 1; i >= 0; --i)
            for(const string &word : wordDict) {
                int m = word.size();
                if(i + m <= n && breakable[i + m] && !s.compare(i, m, word)) {
                    breakable[i] = true;
                    break;
                }
            }
        return breakable[0];
    }
};
