class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> v(min(m, n));
        auto b = v.begin();
        for(int i = 0; i < m; ++i) {
            auto e = b;
            for(int j = 0; i + j < m && j < n; ++j)
                *e++ = mat[i + j][j];
            sort(b, e);
            for(int j = 0; i + j < m && j < n; ++j)
                mat[i + j][j] = v[j];
        }
        for(int i = 1; i < n; ++i) {
            auto e = b;
            for(int j = 0; j < m && i + j < n; ++j)
                *e++ = mat[j][i + j];
            sort(b, e);
            for(int j = 0; j < m && i + j < n; ++j)
                mat[j][i + j] = v[j];
        }
        return mat;
    }
};
