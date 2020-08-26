class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> row_max(n), col_max(n);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                row_max[i] = max(row_max[i], grid[i][j]);
                col_max[j] = max(col_max[j], grid[i][j]);
            }
        }
        int ret = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j)
                ret += min(row_max[i], col_max[j]) - grid[i][j];
        }
        return ret;
    }
};
