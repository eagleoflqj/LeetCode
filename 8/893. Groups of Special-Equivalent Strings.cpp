class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_map<string, int> m;
        int n = A[0].size();
        for(const string &s : A) {
            string ss[2];
            for(int i = 0; i < n; ++i)
                ss[i & 1] += s[i];
            for(int i = 0; i < 2; ++i)
                sort(ss[i].begin(), ss[i].end());
            ++m[move(ss[0]) + move(ss[1])];
        }
        return m.size();
    }
};
