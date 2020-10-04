class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0;
        while(i < n) {
            while((!nums[i] && j < i) || (nums[i] == 2 && i < n - 1))
                swap(nums[i], nums[nums[i] ? --n : j++]);
            ++i;
        }
    }
};
