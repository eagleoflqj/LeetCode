class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> ret(m, vector<int>(n));
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                int m = min(rowSum[i], colSum[j]);
                rowSum[i] -= m;
                colSum[j] -= m;
                ret[i][j] = m;
            }
        return ret;
    }
};
