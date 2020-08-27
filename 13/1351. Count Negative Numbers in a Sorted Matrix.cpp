class Solution {
    const vector<vector<int>> *p;
    int ret = 0;
    void helper(int a, int b, int c, int d) {
        if(a == c || b == d)
            return;
        int h = (a + c) >> 1, v = (b + d) >> 1;
        if((*p)[h][v] < 0) {
            ret += (c - h) * (d - v);
            helper(a, b, c, v);
            helper(a, v, h, d);
        } else {
            helper(h + 1, b, c, v + 1);
            helper(a, v + 1, c, d);
        }
    }
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        p = &grid;
        helper(0, 0, m, n);
        return ret;
    }
};
