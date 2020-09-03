    class Solution {
    public:
        string getHappyString(int n, int k) {
            static const char m[3][3]{"bc", "ac", "ab"};
            if(k > 3 << (n - 1))
                return "";
            string ret{(char)('a' + (--k >> (n - 1)))};
            for(int i = n - 2; i >= 0; --i)
                ret += m[ret.back() - 'a'][(k >> i) & 1];
            return ret;
        }
    };
    