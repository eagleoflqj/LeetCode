class Solution {
public:
    int search(vector<int>& nums, int target) {
        int b = 0, e = nums.size();
        while(b < e) {
            int m = (b + e) >> 1;
            if(nums[m] < target)
                b = m + 1;
            else if(nums[m] > target)
                e = m;
            else
                return m;
        }
        return -1;
    }
};
