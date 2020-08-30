class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size();
        int n = mat[0].size();
        auto row(mat);
        for(int i = 0; i < m; ++i) {
            for(int j = 1; j <= K && j < n; ++j)
                row[i][0] += mat[i][j];
            for(int j = 1; j < n; ++j) {
                row[i][j] = row[i][j - 1];
                if(j + K < n)
                    row[i][j] += mat[i][j + K];
                if(j - K - 1 >= 0)
                    row[i][j] -= mat[i][j - K - 1];
            }
        }
        copy(row[0].begin(), row[0].end(), mat[0].begin());
        for(int j = 0; j < n; ++j) {
            for(int i = 1; i <= K && i < m; ++i)
                mat[0][j] += row[i][j];
            for(int i = 1; i < m; ++i) {
                mat[i][j] = mat[i - 1][j];
                if(i + K < m)
                    mat[i][j] += row[i + K][j];
                if(i - K - 1 >= 0)
                    mat[i][j] -= row[i - K - 1][j];
            }
        }
        return mat;
    }
};
