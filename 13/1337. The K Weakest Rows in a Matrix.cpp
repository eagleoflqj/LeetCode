class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> c(n + 1);
        for(int i = 0; i < m; ++i)
            c[count(mat[i].begin(), mat[i].end(), 1)].push_back(i);
        vector<int> ret;
        for(int i = 0; i <= n; ++i)
            for(int j = 0; k && j < c[i].size(); ++j, --k)
                ret.push_back(c[i][j]);
        return ret;
    }
};
