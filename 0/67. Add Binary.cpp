class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size(), l = max(m, n) + 1, carry = 0;
        a = string(l - m, '0') + a;
        b = string(l - n, '0') + b;
        while(l--) {
            carry += (a[l] - '0') + (b[l] - '0');
            a[l] = (char)((carry & 1) + '0');
            carry >>= 1;
        }
        return a[0] == '0' ? a.substr(1) : a;
    }
};
