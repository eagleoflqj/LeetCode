class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v[10];
        for(int i : nums) {
            string s = to_string(i);
            int c = s[0] - '0';
            v[c].push_back(move(s));
        }
        string ret;
        for(int c = 9; c >= 0; --c) {
            sort(v[c].begin(), v[c].end(), [](const string &s1, const string &s2) {
                return s1 + s2 > s2 + s1;
            });
            for(string &s : v[c])
                ret += move(s);
        }
        if(ret[0] == '0')
            return "0";
        return ret;
    }
};
