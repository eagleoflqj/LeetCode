class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last_occur[128];
        fill(begin(last_occur), end(last_occur), -1);
        int ret = 0, previous = 0, n = s.size();
        for(int i = 0; i < n; ++i) {
            char c = s[i];
            previous = min(i - last_occur[c], previous + 1);
            last_occur[c] = i;
            ret = max(ret, previous);
        }
        return ret;
    }
};
