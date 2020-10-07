class Solution {
public:
    int jump(vector<int>& nums) {
        int dest = nums.size() - 1, i = 0, ret = 0, current = 0;
        while(current < dest) {
            ++ret;
            int last = current;
            for(; i <= last; ++i)
                current = max(current, i + nums[i]);
        }
        return ret;
    }
};
