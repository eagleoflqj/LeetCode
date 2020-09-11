class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int j = i, k = nums[j];
            while(k != j + 1 && k > 0 && k <= n) {
                j = k - 1;
                k = nums[j];
                nums[j] = j + 1;
            }
        }
        for(int i = 0; i < n; ++i)
            if(nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};
