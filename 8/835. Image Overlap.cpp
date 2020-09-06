class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size(), offset = (n << 1) - 1;
        vector<int> vA, vB, count(offset * offset);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) {
                if(A[i][j])
                    vA.emplace_back(i * offset + j);
                if(B[i][j])
                    vB.emplace_back(i * offset + j);
            }
        offset = (n - 1) * (offset + 1);
        for(int a : vA)
            for(int b : vB)
                ++count[a - b + offset];
        return *max_element(count.begin(), count.end());
    }
};
