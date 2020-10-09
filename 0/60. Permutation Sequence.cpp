class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        bitset<10> st;
        --k;
        int fac[10]{1, 1};
        for(int i = 2; i < n; ++i)
            fac[i] = fac[i - 1] * i;
        for(int i = 0; i < n; ++i) {
            div_t d = div(k, fac[n - i - 1]);
            k = d.rem;
            for(int j = 1; j < 10; ++j)
                if(!st[j] && !d.quot--) {
                    ret += (char)(j + '0');
                    st.set(j);
                    break;
                }
        }
        return ret;
    }
};
