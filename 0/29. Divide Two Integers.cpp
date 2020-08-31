class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        bool dd = dividend >= 0, ds = divisor >= 0;
        unsigned p = dividend, q = divisor;
        if(!dd)
            p = -p;
        if(!ds)
            q = -q;
        unsigned ret = 0;
        while(p >= q) {
            unsigned x = p >> 1, y = 0;
            while(x >= q) {
                x >>= 1;
                ++y;
            }
            ret += 1 << y;
            p -= q << y;
        }
        if(dd ^ ds)
            return -ret;
        return ret;
    }
};
