class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        static const int directions[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int limits[2]{n, n - 1}, i = 0, j = -1, d = 0, x = 1;
        while(int k = limits[d & 1]--) {
            do {
                ret[i += directions[d][0]][j += directions[d][1]] = x++;
            } while(--k);
            d = (d + 1) & 3;
        }
        return ret;
    }
};
