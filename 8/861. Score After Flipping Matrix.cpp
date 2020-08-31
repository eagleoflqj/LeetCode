class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        int ret = m;
        for(int j = 1; j < n; ++j) {
            int n_1 = accumulate(A.begin(), A.end(), 0,
                [j](int s, const auto &row) { return s + (row[j] == row[0]); });
            ret = (ret << 1) + max(n_1, m - n_1);
        }
        return ret;
    }
};
