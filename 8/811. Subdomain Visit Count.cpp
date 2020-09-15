class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for(const string &s : cpdomains) {
            int count;
            string domain;
            istringstream(s) >> count >> domain;
            int i = 0, n = domain.size();
            do {
                m[domain.substr(i)] += count;
            } while((i = domain.find('.', i) + 1));
        }
        vector<string> ret;
        for(const auto &p : m)
            ret.push_back(to_string(p.second) + " " + p.first);
        return ret;
    }
};
