class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ret = 0, i = 32;
        while(i--) {
            ret = (ret << 1) | (n & 1);
            n >>= 1;
        }
        return ret;
    }
};
