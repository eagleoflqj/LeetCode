class Solution {
    int m, n;
    void flip(vector<vector<int>> &mat, int i, int j, unsigned &count) {
        ++count;
        mat[i][j] ^= 1;
        if(i)
            mat[i - 1][j] ^= 1;
        if(i + 1 < m)
            mat[i + 1][j] ^= 1;
        if(j)
            mat[i][j - 1] ^= 1;
        if(j + 1 < n)
            mat[i][j + 1] ^= 1;
    }
public:
    int minFlips(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        unsigned ret = -1;
        for(unsigned row = 0; row < 1 << n; ++row) {
            auto temp = mat;
            unsigned count = 0, bits = row;
            for(int j = 0; j < n; ++j) {
                if(bits & 1)
                    flip(temp, 0, j, count);
                bits >>= 1;
            }
            for(int i = 1; i < m; ++i)
                for(int j = 0; j < n; ++j)
                    if(temp[i - 1][j])
                        flip(temp, i, j, count);
            for(int j = 0; j < n; ++j)
                if(temp[m - 1][j])
                    goto fail;
            ret = min(ret, count);
        fail:
            continue;
        }
        return ret;
    }
};
