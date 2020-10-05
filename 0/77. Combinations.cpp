class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(n == k || !k) {
            vector<int> v(k);
            iota(v.begin(), v.end(), 1);
            return {v};
        }
        vector<vector<int>> ret = combine(n - 1, k - 1), temp = combine(n - 1, k);
        for(auto &v : ret)
            v.push_back(n);
        for(auto &&v : temp)
            ret.push_back(move(v));
        return ret;
    }
};
