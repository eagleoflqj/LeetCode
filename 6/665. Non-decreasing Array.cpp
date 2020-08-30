class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int lb = -1e5;
        int n = nums.size();
        bool modified = false;
        for(int i = 0; i < n - 1; lb = nums[i++]) {
            if(nums[i] <= nums[i + 1])
                continue;
            if(modified)
                return false;
            modified = true;
            if(nums[i + 1] < lb)
                nums[i + 1] = nums[i];
            else
                nums[i] = nums[i + 1];
        }
        return true;
    }
};
