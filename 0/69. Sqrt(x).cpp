class Solution {
public:
    int mySqrt(int x) {
        int64_t ret = 1, square;
        do {
            ret = (ret + x / ret) >> 1;
            square = ret * ret;
        } while(!(square <= x && x <= square + (ret << 1)));
        return ret;
    }
};
