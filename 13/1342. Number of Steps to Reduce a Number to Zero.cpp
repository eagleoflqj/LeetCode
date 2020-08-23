class Solution {
public:
    int numberOfSteps(int num) {
        int ret = 0;
        while(num) {
            ++ret;
            if(num & 1)
                num &= ~1;
            else
                num >>= 1;
        }
        return ret;
    }
};
