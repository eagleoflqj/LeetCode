class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        static const int n = 8;
        set<pair<int, int>> st;
        for(const auto &v : queens)
            st.emplace(v[0], v[1]);
        vector<vector<int>> ret;
        pair<int, int> directions[]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for(auto p : directions) {
            int i = king[0], j = king[1];
            while(true) {
                i += p.first; j += p.second;
                if(i < 0 || i >= n || j < 0 || j >= n)
                    break;
                if(st.find({i, j}) != st.end()) {
                    ret.push_back({i, j});
                    break;
                }
            }
        }
        return ret;
    }
};
