class Solution {
public:
    char findKthBit(int n, int k) {
        bool bit = false;
        while(n > 1) {
            int mid = 1 << (n - 1);
            if(k == mid)
                return bit ? '0' : '1';
            if(k > mid) {
                bit = !bit;
                k = (mid << 1) - k;
            }
            --n;
        }
        return bit ? '1' : '0';
    }
};
