class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_multimap<string, int> equation_map;
        for(int i = 0; i < equations.size(); ++i) {
            equation_map.emplace(equations[i][0], i);
            equation_map.emplace(equations[i][1], i);
        }
        int i = 0;
        unordered_map<string, pair<int, double>> m;
        do {
            auto iter = equation_map.begin();
            int index = iter->second;
            string a = equations[index][0], b = equations[index][1];
            m.emplace(a, make_pair(i, values[index]));
            m.emplace(b, make_pair(i, 1.0));
            queue<string> q;
            q.push(move(a));
            q.push(move(b));
            do {
                a = move(q.front());
                double v = m[a].second;
                q.pop();
                for(auto p = equation_map.equal_range(a); p.first != p.second; ++p.first) {
                    index = p.first->second;
                    bool ordered = a == equations[index][0];
                    b = equations[index][ordered];
                    if(m.find(b) == m.end()) {
                        m.emplace(b, make_pair(i, ordered ? v / values[index] : v * values[index]));
                        q.push(move(b));
                    }
                }
                equation_map.erase(a);
            } while(!q.empty());
            ++i;
        } while(!equation_map.empty());
        vector<double> ret;
        auto e = m.end();
        for(const auto &query : queries) {
            auto iter_a = m.find(move(query[0])), iter_b = m.find(move(query[1]));
            ret.push_back(iter_a == e || iter_b == e || iter_a->second.first != iter_b->second.first ?
                -1 : iter_a->second.second / iter_b->second.second);
        }
        return ret;
    }
};
