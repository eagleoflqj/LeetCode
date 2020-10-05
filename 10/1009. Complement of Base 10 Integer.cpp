class Solution {
public:
    int bitwiseComplement(int N) {
        int t = 1;
        while(t < N)
            t = (t << 1) | 1;
        return t ^ N;
    }
};
