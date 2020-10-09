class Solution {
public:
    int uniquePaths(int m, int n) {
        if(--m > --n)
            swap(m, n);
        int64_t C = 1;
        for(int i = 1; i <= m; ++i)
            C = C * (n + i) / i;
        return C;
    }
};
