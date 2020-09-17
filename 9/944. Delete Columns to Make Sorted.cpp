class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size(), m = A[0].size(), ret = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 1; j < n; ++j)
                if(A[j - 1][i] > A[j][i]) {
                    ++ret;
                    break;
                }
        return ret;
    }
};
