class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return;
        int i = n - 1;
        while(i > 0 && nums[i - 1] >= nums[i])
            --i;
        if(i) {
            int j = i;
            while(j < n - 1 && nums[j + 1] > nums[i - 1])
                ++j;
            swap(nums[i - 1], nums[j]);
        }
        for(int j = n - 1; i < j; ++i, --j)
            swap(nums[i], nums[j]);
    }
};
