class Solution {
public:
    int minSteps(int n) {
        int ret = 0;
        for(int p = 2; n > 1; ++p) {
            if(p * p > n)
                return ret + n;
            div_t d;
            while(d = div(n, p), !d.rem) {
                n = d.quot;
                ret += p;
            }
        }
        return ret;
    }
};
