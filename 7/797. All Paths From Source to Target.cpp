class Solution {
    vector<int> path;
    vector<vector<int>> ret;
    vector<vector<int>> *p;
    int dest;
    void helper(int i) {
        path.push_back(i);
        for(auto j : (*p)[i])
            if(j == dest) {
                ret.push_back(path);
                ret.back().push_back(dest);
            }
            else
                helper(j);
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        p = &graph;
        dest = graph.size() - 1;
        helper(0);
        return ret;
    }
};
