class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        int n1 = num1.size(), n2 = num2.size(), n = n1 + n2;
        vector<int> digits(n + 1);
        for(char &c : num2)
            c -= '0';
        for(int i = 0; i < n1; ++i) {
            int c = num1[n1 - i - 1] - '0';
            for(int j = 0; j < n2; ++j)
                digits[i + j] += c * num2[n2 - j - 1];
        }
        for(int i = 0; i < n; ++i) {
            div_t d = div(digits[i], 10);
            digits[i] = d.rem;
            digits[i + 1] += d.quot;
        }
        string ret;
        if(!digits[--n])
            --n;
        do {
            ret += (char)(digits[n] + '0');
        } while(--n >= 0);
        return ret;
    }
};
