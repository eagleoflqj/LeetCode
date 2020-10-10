class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0)
            return false;
        while(!(num & 1))
            num >>= 1;
        div_t d;
        for(int divisor : {3, 5})
            while(d = div(num, divisor), !d.rem)
                num = d.quot;
        return num == 1;
    }
};
