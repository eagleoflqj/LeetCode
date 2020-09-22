class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], count = 1, n = nums.size();
        for(int i = 1; i < n; ++i)
            if(nums[i] == candidate)
                ++count;
            else if(!--count) {
                candidate = nums[i];
                count = 1;
            }
        return candidate;
    }
};
