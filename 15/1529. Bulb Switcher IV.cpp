class Solution {
public:
    int minFlips(string target) {
        bool state = false;
        int ret = 0;
        for(char c : target)
            if(c - '0' != state) {
                state = !state;
                ++ret;
            }
        return ret;
    }
};
