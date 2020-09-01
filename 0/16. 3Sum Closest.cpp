class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = 1e5;
        int n = nums.size();
        for(int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(target - closest) > abs(target - sum))
                    closest = sum;
                if(sum < target)
                    ++left;
                else if(sum > target)
                    --right;
                else
                    return closest;
            }
        }
        return closest;
    }
};
