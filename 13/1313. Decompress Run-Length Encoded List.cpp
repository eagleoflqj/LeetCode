class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        for(int i = 0; i < n; i += 2) {
            const int freq = nums[i], val = nums[i + 1];
            for(int j = 0; j < freq; ++j)
                ret.push_back(val);
        }
        return ret;
    }
};
