class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int next[]{c0, r0, c0, r0}, step[]{1, 1, -1, -1};
        int position[]{c0, r0}, direction = 0;
        vector<vector<int>> ret{{r0, c0}};
        do {
            next[direction] += step[direction];
            while(position[direction & 1] != next[direction]) {
                position[direction & 1] += step[direction];
                if(position[0] >= 0 && position[0] < C && position[1] >=0 && position[1] < R)
                    ret.push_back({position[1], position[0]});
            }
            direction = (direction + 1) & 3;
        } while(ret.size() < R * C);
        return ret;
    }
};
