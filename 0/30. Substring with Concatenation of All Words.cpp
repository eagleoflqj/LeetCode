class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        int n_word = words.size();
        if(!n_word)
            return ret;
        int length = words[0].size(), remain = s.size() - length * n_word;
        if(remain < 0)
            return ret;
        unordered_map<string, int> word_map;
        for(const auto &word : words)
            ++word_map[word];
        unsigned sum = accumulate(word_map.begin(), word_map.end(), 0u,
            [](unsigned i, decltype(*word_map.begin()) p) {
                return i + accumulate(p.first.begin(), p.first.end(), 0u) * p.second;
            });
        unsigned running_sum = accumulate(s.begin(), s.end() - remain, 0u);
        for(int i = 0; i <= remain; running_sum += s[i + length * n_word] - s[i], ++i) {
            if(running_sum != sum)
                continue;
            unordered_map<string, int> running_map(word_map);
            for(int j = 0; j < n_word; ++j) {
                auto iter = running_map.find(s.substr(i + j * length, length));
                if(iter == running_map.end() || --iter->second < 0) {
                    running_map.clear();
                    break;
                }
            }
            if(!running_map.empty())
                ret.push_back(i);
        }
        return ret;
    }
};
