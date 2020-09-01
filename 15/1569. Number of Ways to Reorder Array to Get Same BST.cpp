class Solution {
    static constexpr int mod = 1e9 + 7;
    static inline int multiply(int x, int y) {
        int64_t ret = (int64_t)x * y;
        return ret % mod;
    }
    static int C(int n, int k) {
        static map<pair<int, int>, int> dictionary;
        if(!k)
            return 1;
        auto iter = dictionary.find({n, k});
        if(iter != dictionary.end())
            return iter->second;
        int ret = (C(n - 1, min(k - 1, n - k)) + C(n - 1, min(k, n - 1 - k))) % mod;
        dictionary.insert({{n, k}, ret});
        return ret;
    }
    using Iter = vector<int>::iterator;
    int helper(Iter b, Iter e) {
        if(b == e || b + 1 == e)
            return 1;
        int root = *b++;
        Iter m = stable_partition(b, e, [root](int i) { return i < root; });
        return multiply(C(e - b, min(m - b, e - m)), multiply(helper(b, m), helper(m, e)));
    }
public:
    int numOfWays(vector<int>& nums) {
        return (helper(nums.begin(), nums.end()) + mod - 1) % mod;
    }
};
