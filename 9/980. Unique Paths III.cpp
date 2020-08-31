class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        static const int direction[4][2]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int m = grid.size(), n = grid[0].size();
        int sx, sy, n_empty = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(!grid[i][j])
                    ++n_empty;
                else if(grid[i][j] == 1) {
                    sx = i; sy = j;
                }
        stack<pair<int, int>> stk;
        stk.emplace(sx, sy);
        int ret = 0;
        while(!stk.empty()) {
            auto p = stk.top();
            int &current = grid[p.first][p.second];
            if(current >= 16) {
                current -= 16;
                stk.pop();
                continue;
            }
            auto &d = direction[current >> 2];
            int x = p.first + d[0], y = p.second + d[1];
            current += 4;
            if(x >= 0 && x < m && y >= 0 && y < n) {
                if(!grid[x][y])
                    stk.emplace(x, y);
                else if (grid[x][y] == 2 && stk.size() == n_empty + 1)
                    ++ret;
            }
        }
        return ret;
    }
};
