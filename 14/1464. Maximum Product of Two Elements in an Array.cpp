class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int top1 = nums[0], top2 = 1;
        for(int i = 1; i < n; ++i)
            if(nums[i] >= top1) {
                top2 = top1;
                top1 = nums[i];
            } else if(nums[i] > top2)
                top2 = nums[i];
        return (top1 - 1) * (top2 - 1);
    }
};
