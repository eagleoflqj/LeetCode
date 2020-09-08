class Solution {
public:
    double myPow(double x, int n) {
        if(n == INT_MIN) {
            n = 0xC0000000;
            x *= x;
        }
        if(n < 0) {
            n = -n;
            x = 1 / x;
        }
        double ret = 1;
        while(n) {
            if(n & 1)
                ret *= x;
            x *= x;
            n >>= 1;
        }
        return ret;
    }
};
