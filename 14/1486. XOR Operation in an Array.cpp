class Solution {
public:
    int baseline(int n, int start) {
        int ret = 0;
        while(n--)
            ret ^= start + (n << 1);
        return ret;
    }
    int xorOperation(int n, int start) {
        bool n_odd = n & 1;
        bool least = start & n_odd;
        int ret;
        start >>= 1;
        bool s_odd = start & 1;
        if(n_odd) {
            if(s_odd)
                ret = start ^ ((n >> 1) & 1);
            else
                ret = ((n >> 1) & 1) ^ (start + n - 1);
        } else {
            if(s_odd)
                ret = start ^ (((n - 2) >> 1) & 1) ^ (start + n - 1);
            else
                ret = (n >> 1) & 1;
        }
        return (ret << 1) | least;
    }
};
