class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> depatureCities;
        for(const auto &v : paths)
            depatureCities.insert(v[0]);
        auto end = depatureCities.end();
        for(const auto &v : paths)
            if(depatureCities.find(v[1]) == end)
                return v[1];
        return "";
    }
};
