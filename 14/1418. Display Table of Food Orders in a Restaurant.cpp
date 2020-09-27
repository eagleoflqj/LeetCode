class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> food;
        map<int, unordered_map<string, int>> table;
        for(const auto &order : orders) {
            food.insert(order[2]);
            ++table[stoi(order[1])][order[2]];
        }
        vector<vector<string>> ret{{"Table"}};
        for(const string &s : food)
            ret[0].push_back(s);
        for(auto &p : table) {
            ret.push_back({to_string(p.first)});
            auto e = p.second.end();
            for(const string &s : food) {
                auto iter = p.second.find(s);
                ret.back().push_back(iter == e ? "0" : to_string(iter->second));
            }
        }
        return ret;
    }
};
