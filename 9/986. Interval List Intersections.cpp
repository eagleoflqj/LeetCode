class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ret;
        int m = A.size(), n = B.size(), i = 0, j = 0;
        while(i < m && j < n)
            if(A[i][1] < B[j][0])
                ++i;
            else if(A[i][0] > B[j][1])
                ++j;
            else {
                int left = max(A[i][0], B[j][0]);
                if(A[i][1] <= B[j][1]) {
                    ret.push_back({left, A[i][1]});
                    ++i;
                } else {
                    ret.push_back({left, B[j][1]});
                    ++j;
                }
            }
        return ret;
    }
};
