class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ret = 0, n = nums.size(), i = 0, j = 0, product = 1;
        do {
            int temp = product * nums[j];
            if(temp < k) {
                product = temp;
                ret += j - i + 1;
                ++j;
            } else if(i == j) {
                ++i; ++j;
            } else
                product /= nums[i++];
        } while(j < n);
        return ret;
    }
};
