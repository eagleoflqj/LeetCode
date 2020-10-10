class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int64_t e = INT_MIN - 1LL, ret = 0;
        for(const auto &v : points)
            if(v[0] > e || v[1] < e) {
                ret += v[0] > e;
                e = v[1];
            }
        return ret;
    }
};
