class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ret(A.size());
        auto left = A.begin();
        auto right = A.rbegin();
        for(auto rb = ret.rbegin(), re = ret.rend(); rb != re; ++rb) {
            int x = *left * *left, y = *right * *right;
            if(x < y) {
                *rb = y;
                ++right;
            } else {
                *rb = x;
                ++left;
            }
        }
        return ret;
    }
};
