class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int64_t> dp(n + 1);
        dp[n] = 1;
        for(int i = m - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j)
                dp[j] = obstacleGrid[i][j] ? 0 : dp[j] + dp[j + 1];
            dp[n] = 0;
        }
        return dp[0];
    }
};
