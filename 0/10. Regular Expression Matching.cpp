class Solution {
    vector<pair<char, bool>> pattern;
    string s;
    int m, n;
    vector<vector<bool>> matched;
    void compile(const string &p) {
        int n = p.size(), i = 0;
        while(i < n) {
            if(p[i + 1] != '*') {
                if(!pattern.empty() && pattern.back().first == p[i] && pattern.back().second) // a*a -> aa*
                    pattern.emplace(pattern.end() - 1, p[i], false);
                else
                    pattern.emplace_back(p[i], false);
                ++i;
                continue;
            }
            if(!pattern.empty() && (pattern.back().first == '.' || pattern.back().first == p[i]) && pattern.back().second) { // .*a* -> .*, a*a* -> a*
                i += 2;
                continue;
            }
            if(p[i] == '.') // a*.* -> .*
                while(!pattern.empty() && pattern.back().second)
                    pattern.pop_back();
            pattern.emplace_back(p[i], true);
            i += 2;
        }
        pattern.emplace_back('\0', false);
    }
    bool calculate(int i, int j) {
        if(pattern[j].second) {
            if(matched[i][j + 1])
                return true;
            while(i < m && (pattern[j].first == '.' || s[i] == pattern[j].first)) {
                if(matched[i + 1][j + 1])
                    return true;
                ++i;
            }
            return false;
        } else if(i < m && (s[i] == pattern[j].first || pattern[j].first == '.'))
            return matched[i + 1][j + 1];
        return false;
    }
public:
    bool isMatch(string s, string p) {
        compile(p);
        m = s.size();
        n = pattern.size();
        this->s = move(s);
        for(int i = 0; i <= m; ++i)
            matched.push_back(vector<bool>(n));
        matched[m][n - 1] = true;
        for(int j = n - 2; j >= 0; --j)
            for(int i = m; i >= 0; --i)
                matched[i][j] = calculate(i, j);
        return matched[0][0];
    }
};
