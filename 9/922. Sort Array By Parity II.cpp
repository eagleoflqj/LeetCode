class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size(), i = 0, j = 1;
        while(i < n && j < n)
            if(A[i] & 1) {
                swap(A[i], A[j]);
                j += 2;
            } else
                i += 2;
        return A;
    }
};
