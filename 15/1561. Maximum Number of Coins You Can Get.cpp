class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size() / 3;
        sort(piles.rbegin(), piles.rend()); // GCC's sort(introsort) is faster than partial_sort(heapsort) by a factor of 2 to 5
        int ret = 0;
        while(n--)
            ret += piles[(n << 1) + 1];
        return ret;
    }
};
