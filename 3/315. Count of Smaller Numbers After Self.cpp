class Solution {
    using Vec = vector<tuple<int, int, int>>;
    Vec v, temp;
    Vec::iterator v_beg, temp_beg;
    void helper(int b, int e) {
        if(e - b < 2)
            return;
        int m = (b + e) >> 1;
        helper(b, m);
        helper(m, e);
        copy(v_beg + b, v_beg + e, temp_beg + b);
        int count = 0;
        int i = b, l = b, r = m;
        while(l < m && r < e) {
            if(get<1>(temp[l]) > get<1>(temp[r])) {
                ++count;
                v[i++] = temp[r++];
            } else {
                get<2>(temp[l]) += count;
                v[i++] = temp[l++];
            }
        }
        while(l < m) {
            get<2>(temp[l]) += count;
            v[i++] = temp[l++];
        }
        copy(temp_beg + r, temp_beg + e, v_beg + r);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        temp.resize(n);
        temp_beg = temp.begin();
        v.reserve(n);
        for(int i = 0; i < n; ++i)
            v.emplace_back(i, nums[i], 0);
        v_beg = v.begin();
        helper(0, n);
        vector<int> ret(n);
        for(const auto &t : v)
            ret[get<0>(t)] = get<2>(t);
        return ret;
    }
};
