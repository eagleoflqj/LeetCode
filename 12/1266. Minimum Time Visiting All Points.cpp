class Solution {
public:
    static inline int distance(vector<int> &p1, vector<int> &p2) {
        return max(abs(p1[0] - p2[0]), abs(p1[1] - p2[1]));
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ret = 0;
        for(int i = 0; i < n - 1; ++i)
            ret += distance(points[i], points[i + 1]);
        return ret;
    }
};
