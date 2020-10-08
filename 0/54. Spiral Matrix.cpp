class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return {};
        int limits[2]{(int)matrix[0].size(), (int)matrix.size() - 1}, i = 0, j = -1, d = 0;
        static const int directions[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> ret;
        while(int k = limits[d & 1]--) {
            do {
                ret.push_back(matrix[i += directions[d][0]][j += directions[d][1]]);
            } while(--k);
            d = (d + 1) & 3;
        }
        return ret;
    }
};
