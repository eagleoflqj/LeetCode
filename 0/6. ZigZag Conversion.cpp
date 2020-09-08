class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int period = (numRows - 1) << 1, n = s.size();
        string ret;
        for(int j = 0; j < n; j += period)
            ret += s[j];
        for(int i = 1; i < numRows - 1; ++i)
            for(int j = i; j < n; j += period) {
                ret += s[j];
                int up = j + period - (i << 1);
                if(up < n)
                    ret += s[up];
            }
        for(int j = numRows - 1; j < n; j += period)
            ret += s[j];
        return ret;
    }
};
