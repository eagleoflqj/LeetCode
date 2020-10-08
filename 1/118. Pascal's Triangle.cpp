class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for(int i = 0; i < numRows; ++i) {
            ret.push_back({1});
            for(int j = 0; j < i >> 1; ++j)
                ret.back().push_back(ret[i - 1][j] + ret[i - 1][j + 1]);
            for(int j = 0; j < (i + 1) >> 1; ++j)
                ret.back().push_back(ret.back()[((i - 1) >> 1) - j]);
        }
        return ret;
    }
};
