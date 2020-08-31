class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ret = accumulate(matrix[0].begin(), matrix[0].end(), 0);
        for(int i = 1; i < m; ++i) {
            ret += matrix[i][0];
            for(int j = 1; j < n; ++j) {
                if(!matrix[i][j])
                    continue;
                int left = matrix[i - 1][j], up = matrix[i][j - 1];
                if(left == up)
                    matrix[i][j] = left + (matrix[i - left][j - left] > 0);
                else
                    matrix[i][j] = min(left, up) + 1;
                ret += matrix[i][j];
            }
        }
        return ret;
    }
};
