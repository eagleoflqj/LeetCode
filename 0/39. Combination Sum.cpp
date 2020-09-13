class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int start = 0) {
        int n = candidates.size();
        vector<vector<int>> ret;
        for(int i = start; i < n; ++i)
            if(candidates[i] < target)
                for(auto &&v : combinationSum(candidates, target - candidates[i], i)) {
                    v.push_back(candidates[i]);
                    ret.push_back(move(v));
                }
            else if(candidates[i] == target)
                ret.push_back({candidates[i]});
        return ret;
    }
};
