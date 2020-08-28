class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ret = 0, i = 0;
        while(m--) {
            const auto &row = grid[m];
            while(i < n && row[i] >= 0)
                ++i;
            if(i == n)
                break;
            ret += n - i;
        }
        return ret;
    }
};
