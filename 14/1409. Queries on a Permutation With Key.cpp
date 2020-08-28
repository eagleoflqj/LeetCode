namespace {
    constexpr int LB = 1;
    constexpr int UB = 1000;
}

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        FenwickTree<(UB - LB + 1) << 1> tree;
        vector<int> v(m + 1);
        for(int i = 1; i <= m; ++i) {
            tree.update(m + i, 1);
            v[i] = m + i;
        }
        vector<int> ret;
        for(auto i : queries) {
            ret.push_back(tree.partial_sum(v[i] - 1));
            tree.update(v[i], -1);
            tree.update(m, 1);
            v[i] = m--;
        }
        return ret;
    }
};
