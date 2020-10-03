class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i : nums)
            ++m[i];
        if(!k)
            return count_if(m.begin(), m.end(), [](auto p) { return p.second > 1; });
        auto e = m.end();
        return count_if(m.begin(), m.end(), [&, k](auto p) { return m.find(p.first + k) != e; });
    }
};
