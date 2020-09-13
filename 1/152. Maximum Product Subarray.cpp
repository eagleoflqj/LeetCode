class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret = nums[0], M = nums[0], m = 0, n = nums.size();
        if(nums[0] < 0)
            swap(m, M);
        for(int i = 1; i < n; ++i) {
            if(nums[i] >= 0) {
                M = max(nums[i], nums[i] * M);
                m *= nums[i];
            } else if(nums[i] < 0) {
                int t = nums[i] * m;
                m = min(nums[i], nums[i] * M);
                M = t;
            }
            ret = max(ret, M);
        }
        return ret;
    }
};
