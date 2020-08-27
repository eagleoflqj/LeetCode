class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 1)
            return vector<int>{0};
        vector<int> v(n);
        iota(v.begin(), v.end() - 1, 1);
        v[n - 1] = -((n * (n - 1)) >> 1);
        return v;
    }
};
