class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), ret = 0;
        for(int i = 0; i < n; ++i)
            ret += mat[i][i] + mat[i][n - 1 - i];
        if(n & 1)
            ret -= mat[n >> 1][n >> 1];
        return ret;
    }
};
