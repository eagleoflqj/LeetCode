class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted(nums), ret;
        auto b = sorted.begin(), e = sorted.end();
        sort(b, e);
        for(auto i : nums) {
            auto iter = lower_bound(b, e, i);
            ret.push_back(iter - b);
        }
        return ret;
    }
};
