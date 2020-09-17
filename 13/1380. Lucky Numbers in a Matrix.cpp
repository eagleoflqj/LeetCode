class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ret;
        for(const auto &row : matrix) {
            int lucky = min_element(row.begin(), row.end()) - row.begin(), v = row[lucky];
            if(all_of(matrix.begin(), matrix.end(),
                [=](const auto &r) { return r[lucky] <= v; }))
                ret.push_back(v);
        }
        return ret;
    }
};
