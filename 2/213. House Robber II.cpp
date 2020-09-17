class Solution {
    int helper(const vector<int> &nums, int b, int e, int with, int without) {
        for(int i = b; i < e; ++i) {
            int temp = without + nums[i];
            without = max(with, without);
            with = temp;
        }
        return max(with, without);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        return max(helper(nums, 2, n - 1, 0, nums[0]), helper(nums, 1, n, 0, 0));
    }
};
