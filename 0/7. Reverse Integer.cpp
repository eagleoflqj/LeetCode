class Solution {
public:
    int reverse(int x) {
        static const int pre_max = INT_MAX / 10;
        if(x == INT_MIN)
            return 0;
        bool negative = false;
        if(x < 0) {
            negative = true;
            x = -x;
        }
        int ret = 0;
        while(x) {
            div_t d = div(x, 10);
            if(ret > pre_max)
                return 0;
            ret = ret * 10 + d.rem;
            x = d.quot;
        }
        return negative ? -ret : ret;
    }
};
