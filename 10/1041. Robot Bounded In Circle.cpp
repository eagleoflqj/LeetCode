class Solution {
public:
    bool isRobotBounded(string instructions) {
        pair<int, int> direction[]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0, x = 0, y = 0;
        for(char c : instructions)
            if(c == 'G') {
                x += direction[d].first;
                y += direction[d].second;
            } else
                d = (d + (c == 'L' ? 3 : 1)) & 3;
        return (!x && !y) || d;
    }
};
