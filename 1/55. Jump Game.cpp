class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dest = 0, n = nums.size() - 1;
        for(int i = 0; i < n && i <= dest; ++i)
            dest = max(dest, i + nums[i]);
        return dest >= n;
    }
};
