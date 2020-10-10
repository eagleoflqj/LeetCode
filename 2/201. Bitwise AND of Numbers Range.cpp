class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ret = 0, shift = 0;
        while(n) {
            if((n & 1) == (m & 1))
                ret |= (n & 1) << shift;
            else
                ret = 0;
            n >>= 1;
            m >>= 1;
            ++shift;
        }
        return ret;
    }
};
