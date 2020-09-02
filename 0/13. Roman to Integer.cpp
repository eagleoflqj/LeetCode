class Solution {
public:
    int romanToInt(string s) {
        static map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ret = 0, n = s.size(), i = 0;
        for(int i = 0; i < n; ++i) {
            int v = m[s[i]], next;
            if(i + 1 < n && (next = m[s[i + 1]]) > v) {
                v = next - v;
                ++i;
            }
            ret += v;
        }
        return ret;
    }
};
