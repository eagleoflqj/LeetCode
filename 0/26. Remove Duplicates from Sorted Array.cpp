class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), i = 0;
        for(int j = 1; j < n; ++j)
            if(nums[j] != nums[i])
                nums[++i] = nums[j];
        return n ? i + 1 : 0;
    }
};
