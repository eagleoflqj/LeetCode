class Solution {
public:
    string freqAlphabets(string s) {
        static constexpr int shift = -'0' - 1 + 'a';
        string ret;
        int i = 0, n = s.size();
        while(i < n) {
            if(i + 2 < n && s[i + 2] == '#') {
                ret += (s[i] - '0') * 10 + s[i + 1] + shift;
                i += 3;
            } else
                ret += s[i++] + shift;
        }
        return ret;
    }
};
