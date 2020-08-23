class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto i : nums)
            ++m[i];
        int ret = 0;
        for(auto &p : m) {
            int n = p.second;
            ret += n * (n - 1) >> 1;
        }
        return ret;
    }
};
