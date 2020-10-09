class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), dp = nums[0], ret = dp;
        for(int i = 1; i < n; ++i) {
            dp = max(dp, 0) + nums[i];
            ret = max(ret, dp);
        }
        return ret;
    }
};
