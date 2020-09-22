class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        for(int i : nums) {
            int j = abs(i) - 1;
            if(nums[j] > 0)
                nums[j] = -nums[j];
            else
                ret.push_back(j + 1);
        }
        return ret;
    }
};
