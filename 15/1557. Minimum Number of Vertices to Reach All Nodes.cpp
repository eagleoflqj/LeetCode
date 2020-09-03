class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> n_points_to(n);
        for(const auto &edge : edges)
            n_points_to[edge[1]] = true;
        vector<int> ret;
        for(int i = 0; i < n; ++i)
            if(!n_points_to[i])
                ret.push_back(i);
        return ret;
    }
};
