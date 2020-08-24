class Solution {
public:
    using Tup = tuple<int64_t, int64_t, int64_t>;
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ret = 0;
        sort(points.begin(), points.end()); // cluster the same points
        map<Tup, pair<int, int>> h; // <line, <the point that creates it, the number of points on it>>
        for(int i = 0, next_i = 0; next_i < n; i = next_i) {
            auto &p1 = points[i];
            while(next_i < n && p1 == points[next_i]) // find next point
                ++next_i;
            if(!i) // consider single points
                ret = next_i;
            for(int j = next_i, next_j = next_i; j < n; j = next_j) {
                auto &p2 = points[j];
                while(next_j < n && p2 == points[next_j])
                    ++next_j;
                int64_t A = p2[1] - p1[1]; // Ax+By=C
                int64_t B = p1[0] - p2[0];
                int64_t C = A * p2[0] + B * p2[1]; // may overflow
                if(A < 0 || (A == 0 && B < 0)) {
                    A = -A; B = -B; C = -C;
                }
                int g = gcd(A, B);
                auto iter_bool = h.emplace(Tup(A / g, B / g, C / g), make_pair(i, next_i - i)); // no change if exists
                auto &p = iter_bool.first->second;
                if(p.first == i) // no duplicate
                    p.second += next_j - j;
            }
        }
        for(auto &line : h)
            ret = max(line.second.second, ret);
        return ret;
    }
};
