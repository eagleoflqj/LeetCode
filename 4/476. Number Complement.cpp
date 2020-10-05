class Solution {
public:
    int findComplement(int num) {
        int t = 1;
        while(t < num)
            t = (t << 1) | 1;
        return t ^ num;
    }
};
