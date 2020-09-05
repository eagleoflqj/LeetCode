class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, pair<int, int>> m{{0, {-1, 1}}};
        int n = arr.size(), ret = 0, partial_xor = 0;
        for(int i = 0; i < n; ++i) {
            partial_xor ^= arr[i];
            auto &p = m[partial_xor];
            ret += (i - 1) * p.second - p.first;
            p.first += i;
            ++p.second;
        }
        return ret;
    }
};
