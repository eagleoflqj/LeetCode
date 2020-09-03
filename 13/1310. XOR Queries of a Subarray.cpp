class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int M = (*max_element(queries.begin(), queries.end(),
            [](const auto &v1, const auto &v2) { return v1[1] < v2[1]; }))[1];
        vector<int> partial_xor{0}, ret;
        partial_sum(arr.begin(), arr.begin() + M + 1, back_inserter(partial_xor),
            [](int x, int y) { return x ^ y; });
        for(const auto &query : queries)
            ret.push_back(partial_xor[query[0]] ^ partial_xor[query[1] + 1]);
        return ret;
    }
};
