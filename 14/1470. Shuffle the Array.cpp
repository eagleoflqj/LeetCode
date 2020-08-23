class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ret(n << 1);
        for(int i = 0; i < n; ++i) {
            int j = i << 1;
            ret[j] = nums[i];
            ret[j + 1] = nums[i + n];
        }
        return ret;
    }
};
