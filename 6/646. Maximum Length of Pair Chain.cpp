class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        pair<int, int> current{pairs[0][0], pairs[0][1]};
        int n = pairs.size(), ret = 1;
        for(int i = 1; i < n; ++i) {
            bool disjoint = pairs[i][0] > current.second, subset = pairs[i][1] < current.second;
            if(disjoint || subset) {
                current = {pairs[i][0], pairs[i][1]};
                if(disjoint)
                    ++ret;
            }
        }
        return ret;
    }
};
