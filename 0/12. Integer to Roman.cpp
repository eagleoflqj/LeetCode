class Solution {
    string value(int digit, char one, char five, char ten) {
        if(!digit)
            return "";
        if(digit <= 3)
            return string(digit, one);
        if(digit <= 5)
            return string(5 - digit, one) + five;
        if(digit <= 8)
            return five + string(digit - 5, one);
        return string{one, ten};
    }
public:
    string intToRoman(int num) {
        static char m[]{'I', 'V', 'X', 'L', 'C', 'D', 'M', 0, 0};
        string ret;
        for(int i = 0; num; i += 2) {
            div_t d = div(num, 10);
            ret = value(d.rem, m[i], m[i + 1], m[i + 2]) + ret;
            num = d.quot;
        }
        return ret;
    }
};
