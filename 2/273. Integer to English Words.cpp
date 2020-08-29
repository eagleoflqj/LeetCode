class Solution {
public:
    string numberToWords(int num) {
        static const string dic20[] {
            "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
            "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        };
        static const string dic100[] {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        static const string h = "Hundred";
        static const string huge[] {"Thousand", "Million", "Billion"};
        if(num < 20)
            return dic20[num];
        if(num < 100) {
            div_t d = div(num, 10);
            return dic100[d.quot - 2] + (d.rem ? " " + dic20[d.rem] : "");
        }
        if(num < 1000) {
            div_t d = div(num, 100);
            return dic20[d.quot] + " " + h + (d.rem ? " " + numberToWords(d.rem) : "");
        }
        int i = 0;
        string ret;
        do {
            div_t d = div(num, 1000);
            if(d.rem)
                ret = numberToWords(d.rem) + (i ? " " + huge[i - 1] : "") + (ret.empty() ? "" : " " + ret);
            ++i;
            num = d.quot;
        } while(num);
        return ret;
    }
};
