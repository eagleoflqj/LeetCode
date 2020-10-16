class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        static const int directions[4][2]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int m = grid.size(), n = grid[0].size(), ret = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j] == '1') {
                    ++ret;
                    stack<pair<int, int>> stk;
                    stk.emplace(i, j);
                    while(!stk.empty()) {
                        auto p = stk.top();
                        stk.pop();
                        grid[p.first][p.second] = '2';
                        for(auto &direction : directions) {
                            int x = p.first + direction[0], y = p.second + direction[1];
                            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1')
                                stk.emplace(x, y);
                        }
                    }
                }
        return ret;
    }
};
