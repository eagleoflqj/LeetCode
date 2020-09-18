class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(auto &s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            m[move(key)].push_back(move(s));
        }
        vector<vector<string>> ret;
        for(auto &p : m)
            ret.push_back(move(p.second));
        return ret;
    }
};
