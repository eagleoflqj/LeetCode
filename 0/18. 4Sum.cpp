class Solution {
    using Iter = vector<int>::iterator;
    static inline void advance_out(Iter &iter, const Iter &constraint) {
        auto i = *iter;
        while(++iter != constraint && *iter == i);
    }
    static inline void retreat_out(Iter &iter, const Iter &constraint) {
        auto i = *iter;
        while(--iter != constraint && *iter == i);
    }
    vector<vector<int>> nSum(const Iter &b, const Iter &e, int n, int target) {
        vector<vector<int>> ret;
        if(b == e)
            return ret;
        if(n == 2) {
            Iter left = b, right = e - 1;
            while(left < right) {
                int sum = *left + *right;
                if(sum < target)
                    retreat_out(right, b);
                else if(sum > target)
                    advance_out(left, e);
                else {
                    ret.push_back({*right, *left});
                    advance_out(left, e);
                    retreat_out(right, b);
                }
            }
            return ret;
        }
        for(Iter iter = b; iter + n <= e; advance_out(iter, e)) {
            for(auto &&v : nSum(iter + 1, e, n - 1, target - *iter)) {
                ret.emplace_back(move(v));
                ret.back().push_back(*iter);
            }
        }
        return ret;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.rbegin(), nums.rend());
        return nSum(nums.begin(), nums.end(), 4, target);
    }
};
