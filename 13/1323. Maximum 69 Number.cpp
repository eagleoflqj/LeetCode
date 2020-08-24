class Solution {
public:
    int maximum69Number (int num) {
        int base = 1, addition = 0;
        int n = num;
        do {
            div_t d = div(n, 10);
            if(d.rem == 6)
                addition = base;
            base *= 10;
            n = d.quot;
        } while(n);
        return num + addition * 3;
    }
};
