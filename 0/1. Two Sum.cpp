class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = nums.size();
        vector<int> ret{-1, -1};
        for(int i = 0; i < n; ++i) {
            auto iter = m.find(target - nums[i]);
            if(iter != m.end()) {
                ret = {iter->second, i};
                return ret;
            }
            m.emplace(nums[i], i);
        }
        return ret;
    }
};
