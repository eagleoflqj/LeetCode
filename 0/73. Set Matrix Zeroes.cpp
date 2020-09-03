class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int x, y;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(!matrix[i][j]) {
                    x = i; y = j;
                    goto exist_zero;
                }
        return;
    exist_zero:
        for(int i = x + 1; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(j == y)
                    continue;
                if(!matrix[i][j])
                    matrix[x][j] = matrix[i][y] = 0;
            }
        for(int i = x + 1; i < m; ++i)
            if(!matrix[i][y])
                fill(matrix[i].begin(), matrix[i].end(), 0);
            else
                matrix[i][y] = 0;
        for(int j = 0; j < n; ++j) {
            if(!matrix[x][j])
                for(int i = 0; i < m; ++i)
                    matrix[i][j] = 0;
            else
                matrix[x][j] = 0;
        }
    }
};
