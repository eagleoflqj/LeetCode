class Solution {
public:
    int climbStairs(int n) {
        int f0 = 1, f1 = 1;
        while(--n) {
            int t = f1;
            f1 += f0;
            f0 = t;
        }
        return f1;
    }
};
