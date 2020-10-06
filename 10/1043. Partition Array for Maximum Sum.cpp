class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(k);
        int M = arr[0], i = 0, n = arr.size();
        for(; i < k; ++i) {
            M = max(M, arr[i]);
            dp[i] = M * (i + 1);
        }
        for(; i < n; ++i) {
            M = arr[i];
            int temp = M;
            for(int j = 0; j < k; ++j) {
                M = max(M, arr[i - j]);
                temp = max(temp, M * (j + 1) + dp[(i + k - j - 1) % k]);
            }
            dp[i % k] = temp;
        }
        return dp[(n - 1) % k];
    }
};
