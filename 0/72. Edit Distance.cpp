class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        if(n1 > n2) {
            swap(word1, word2);
            swap(n1, n2);
        }
        vector<int> dpp(n1 + 1), dp(n1 + 1);
        iota(dp.begin(), dp.end(), 0);
        for(int j = 1; j <= n2; ++j) {
            swap(dpp, dp);
            dp[0] = j;
            for(int i = 1; i <= n1; ++i)
                dp[i] = word1[i - 1] == word2[j - 1] ? dpp[i - 1] : min({dpp[i - 1], dpp[i], dp[i - 1]}) + 1;
        }
        return dp[n1];
    }
};
