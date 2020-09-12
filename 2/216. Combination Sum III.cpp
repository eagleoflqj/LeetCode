class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n, int start = 1) {
        if(k == 1)
            if(n >= start && n <= 9)
                return {{n}};
            else
                return {};
        vector<vector<int>> ret;
        for(int i = start; i <= (n - 1) / k; ++i)
            for(auto &&v : combinationSum3(k - 1, n - i, i + 1)) {
                v.push_back(i);
                ret.push_back(move(v));
            }
        return ret;
    }
};
