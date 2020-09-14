class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), ret = 0;
        vector<int> row(m), column(n);
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                row[i] += mat[i][j];
                column[j] += mat[i][j];
            }
        for(int i = 0; i < m; ++i) {
            if(row[i] != 1)
                continue;
            for(int j = 0; j < n; ++j)
                if(mat[i][j]) {
                    if(column[j] == 1)
                        ++ret;
                    break;
                }
        }
        return ret;
    }
};
