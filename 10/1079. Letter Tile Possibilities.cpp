class Solution {
    static int C(int n, int k) {
        return k ? C(n - 1, k - 1) * n / k : 1;
    }
    vector<int> arrange(const vector<int> &v, int m) {
        int n = v.size();
        vector<int> ret(n + m);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j <= m; ++j)
                ret[i + j] += C(i + j, min(i, j)) * v[i];
        return ret;
    }
public:
    int numTilePossibilities(string tiles) {
        map<char, int> m;
        for(char c : tiles)
            ++m[c];
        vector<int> num{1};
        for(auto p : m) {
            num = arrange(num, p.second);
        }
        return accumulate(num.begin(), num.end(), -1);
    }
};
