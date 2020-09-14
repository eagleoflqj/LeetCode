class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        int with = nums[0], without = 0;
        for(int i = 1; i < n; ++i) {
            int temp = nums[i] + without;
            without = max(with, without);
            with = temp;
        }
        return max(with, without);
    }
};
