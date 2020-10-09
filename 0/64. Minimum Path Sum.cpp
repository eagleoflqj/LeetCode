class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int j = n - 2; j >= 0; --j)
            grid[m - 1][j] += grid[m - 1][j + 1];
        for(int i = m - 2; i >= 0; --i) {
            grid[i][n - 1] += grid[i + 1][n - 1];
            for(int j = n - 2; j >= 0; --j)
                grid[i][j] += min(grid[i][j + 1], grid[i + 1][j]);
        }
        return grid[0][0];
    }
};
