class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        unordered_map<int, int> left, right;
        unordered_set<int> st(nums.begin(), nums.end());
        int ret = 0;
        for(int i : st) {
            int lb = i, ub = i;
            auto iter = right.find(i - 1);
            if(iter != right.end()) {
                lb = iter->second;
                right.erase(iter);
            }
            iter = left.find(i + 1);
            if(iter != left.end()) {
                ub = iter->second;
                left.erase(iter);
            }
            left[lb] = ub;
            right[ub] = lb;
            ret = max(ret, ub - lb);
        }
        return ret + 1;
    }
};
