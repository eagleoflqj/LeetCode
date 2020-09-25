class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int xy = 0, n = grid.size();
        vector<int> xz(n), yz(n);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) {
                int h = grid[i][j];
                if(h) {
                    ++xy;
                    yz[i] = max(yz[i], h);
                    xz[j] = max(xz[j], h);
                }
            }
        return xy + accumulate(yz.begin(), yz.end(), 0) + accumulate(xz.begin(), xz.end(), 0);
    }
};
