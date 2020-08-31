class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size();
        int n = mat[0].size();
        auto partial_sum(mat);
        for(int j = 1; j < n; ++j)
            partial_sum[0][j] += partial_sum[0][j - 1];
        for(int i = 1; i < m; ++i) {
            partial_sum[i][0] += partial_sum[i - 1][0];
            for(int j = 1; j < n; ++j)
                partial_sum[i][j] += partial_sum[i][j - 1] + partial_sum[i - 1][j] - partial_sum[i - 1][j - 1];
        }
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                int mx = max(0, i - K), my = max(0, j - K);
                int Mx = min(m - 1, i + K), My = min(n - 1, j + K);
                mat[i][j] = partial_sum[Mx][My] - (mx ? partial_sum[mx - 1][My] : 0)
                    - (my ? partial_sum[Mx][my - 1] : 0) + (mx && my ? partial_sum[mx - 1][my - 1] : 0);
            }
        return mat;
    }
};
