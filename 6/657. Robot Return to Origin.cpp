class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(char c : moves) {
            if(c == 'D')
                --y;
            else if (c == 'L')
                --x;
            else if(c == 'R')
                ++x;
            else
                ++y;
        }
        return !(x || y);
    }
};