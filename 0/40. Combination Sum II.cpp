class Solution {
    unordered_map<int, int> m;
    using Iter = decltype(m.begin());

    vector<vector<int>> helper(Iter iter, int target) {
        vector<vector<int>> ret;
        while(iter != m.end()) {
            Iter current = iter++;
            for(int i = 1, new_target = target; i <= current->second; ++i) {
                new_target -= current->first;
                if(!new_target)
                    ret.emplace_back(i, current->first);
                else if(new_target > 0)
                    for(auto &&v : helper(iter, new_target)) {
                        fill_n(back_inserter(v), i, current->first);
                        ret.push_back(move(v));
                    }
            }
        }
        return ret;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for(int i : candidates)
            ++m[i];
        return helper(m.begin(), target);
    }
};
