class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        int p2 = 0, p3 = 0, p5 = 0, next2 = 1, next3 = 1, next5 = 1;
        for(int i = 0; i < n; ++i) {
            dp[i] = min({next2, next3, next5});
            if(dp[i] == next2)
                next2 = dp[p2++] << 1;
            if(dp[i] == next3)
                next3 = dp[p3++] * 3;
            if(dp[i] == next5)
                next5 = dp[p5++] * 5;
        }
        return dp[n - 1];
    }
};
