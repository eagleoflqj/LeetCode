class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n_row = matrix.size();
        if(!n_row)
            return false;
        int n = matrix[0].size(), b = 0, e = n_row * n;
        while(b < e) {
            int m = (b + e) >> 1;
            div_t d = div(m, n);
            int x = matrix[d.quot][d.rem];
            if(x < target)
                b = m + 1;
            else if(x > target)
                e = m;
            else
                return true;
        }
        return false;
    }
};
