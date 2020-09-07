class Solution {
    void partition(unordered_set<int> &points, const unordered_multimap<int, int> &edges) {
        queue<int> q;
        q.push(*points.begin());
        do {
            int p = q.front();
            q.pop();
            points.erase(p);
            auto iter_pair = edges.equal_range(p);
            for(auto iter = iter_pair.first; iter != iter_pair.second; ++iter)
                if(points.erase(iter->second))
                    q.push(iter->second);
        } while(!q.empty());
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        unordered_multimap<int, int> edge_type[3];
        unordered_set<int> point_type[3];
        int n_edge[3]{};
        for(const auto &edge : edges) {
            int type = edge[0] - 1;
            edge_type[type].emplace(edge[1], edge[2]);
            edge_type[type].emplace(edge[2], edge[1]);
            point_type[type].insert(edge[1]);
            point_type[type].insert(edge[2]);
            ++n_edge[type];
        }
        if(n_edge[0] + n_edge[2] < n - 1 || n_edge[1] + n_edge[2] < n - 1)
            return -1;
        int n_blue_part = 0, n_blue_point = point_type[2].size();
        auto blue_point(point_type[2]);
        while(!blue_point.empty()) {
            ++n_blue_part;
            partition(blue_point, edge_type[2]);
        }
        for(int i = 0; i < 2; ++i) {
            for(int point : point_type[2])
                point_type[i].insert(point);
            if(point_type[i].size() < n)
                return -1;
            for(auto edge : edge_type[2])
                edge_type[i].insert(edge);
            partition(point_type[i], edge_type[i]);
            if(!point_type[i].empty())
                return -1;
        }
        int n_blue_edge = n_blue_point - n_blue_part;
        return edges.size() - (((n - 1) << 1) - n_blue_edge);
    }
};
