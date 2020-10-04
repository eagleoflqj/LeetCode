class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &v1, const auto &v2) {
            return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] > v2[1]);
        });
        int M = -1, ret = 0;
        for(const auto &interval : intervals)
            if(interval[1] > M) {
                M = interval[1];
                ++ret;
            }
        return ret;
    }
};
