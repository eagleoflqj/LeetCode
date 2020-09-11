class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int b = 0, e = nums.size();
        while(b < e) {
            int m = (b + e) >> 1;
            if(nums[m] > target)
                e = m;
            else if(nums[m] < target)
                b = m + 1;
            else
                return m;
        }
        return b;
    }
};
