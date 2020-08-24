class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<char> row(n), col(m);
        for(auto &p : indices) {
            row[p[0]] ^= 1;
            col[p[1]] ^= 1;
        }
        int odd_row = count(row.begin(), row.end(), 1);
        int odd_col = count(col.begin(), col.end(), 1);
        return odd_row * m + (n - (odd_row << 1)) * odd_col;
    }
};
