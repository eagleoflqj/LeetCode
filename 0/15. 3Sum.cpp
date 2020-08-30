class Solution {
    using Iter = vector<int>::iterator;
    static inline void advance_out(Iter &iter, const Iter &constraint, int i) {
        while(++iter != constraint && *iter == i);
    }
    static inline void retreat_out(Iter &iter, int i) {
        while(*--iter == i);
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        auto e = nums.end();
        for(auto iter = nums.begin(), next = iter; iter != e; iter = next) {
            int i = *iter;
            advance_out(next, e, i);
            if(i >= 0) {
                if(!i && next - iter >= 3)
                    ret.push_back({0, 0, 0});
                break;
            }
            if(next - iter >= 2 && binary_search(next, e, -2 * i))
                ret.push_back({i, i, -2 * i});
            auto left = next, right = e - 1;
            while(left < right) {
                int l = *left, r = *right, sum = i + l + r;
                if(!sum) {
                    ret.push_back({i, l, r});
                    if(l == r)
                        break;
                    advance_out(left, e, l);
                    retreat_out(right, r);
                } else if(sum < 0)
                    advance_out(left, e, l);
                else
                    retreat_out(right, r);
            }
        }
        return ret;
    }
};
