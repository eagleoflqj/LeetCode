class Solution {
public:
    int myAtoi(string str) {
        static const int pre_max = INT_MAX / 10;
        int n = str.size(), i = 0, ret = 0;
        bool negative = false;
        while(i < n && isspace(str[i]))
            ++i;
        if(str[i] == '-') {
            negative = true;
            ++i;
        } else if (str[i] == '+')
            ++i;
        while(i < n && isdigit(str[i])) {
            int d = str[i++] - '0';
            if(ret > pre_max || (ret == pre_max && d > 7))
                return INT_MAX;
            if(ret < -pre_max || (ret == -pre_max && d > 8))
                return INT_MIN;
            ret *= 10;
            if(negative)
                ret -= d;
            else
                ret += d;
        }
        return ret;
    }
};
