class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        for(int i : arr)
            ++m[i];
        int n = arr.size();
        vector<int> v(n + 1);
        for(const auto &p : m)
            ++v[p.second];
        int ret = 0, count = 0;
        for(int i = n, half = n >> 1; count < half; --i) {
            int taken = min(v[i], (half - count + i - 1) / i);
            ret += taken;
            count += i * taken;
        }
        return ret;
    }
};
