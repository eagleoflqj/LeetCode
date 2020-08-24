class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int, int>> v;
        int n = groupSizes.size();
        for(int i = 0; i < n; ++i)
            v.emplace_back(groupSizes[i], i);
        sort(v.begin(), v.end());
        vector<vector<int>> ret;
        for(int i = 0; i < n;) {
            int size = v[i].first;
            ret.push_back({});
            for(int j = 0; j < size; ++j)
                ret.back().push_back(v[i++].second);
        }
        return ret;
    }
};
