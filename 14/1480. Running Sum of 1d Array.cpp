class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ret;
        partial_sum(nums.begin(), nums.end(), back_inserter(ret));
        return ret;
    }
};
