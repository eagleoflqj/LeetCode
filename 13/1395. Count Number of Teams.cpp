class Solution {
    using Vec = vector<tuple<int, int, int, int>>;
    Vec v, temp;
    Vec::iterator v_beg, temp_beg;
    void helper(int b, int e) {
        if(e - b < 2)
            return;
        int m = (b + e) >> 1;
        helper(b, m);
        helper(m, e);
        copy(v_beg + b, v_beg + e, temp_beg + b);
        int smaller_before = 0, smaller_after = 0;
        int i = b, l = b, r = m;
        while(l < m && r < e) {
            if(get<1>(temp[l]) > get<1>(temp[r])) {
                ++smaller_after;
                get<2>(temp[r]) += smaller_before;
                v[i++] = temp[r++];
            } else {
                ++smaller_before;
                get<3>(temp[l]) += smaller_after;
                v[i++] = temp[l++];
            }
        }
        while(l < m) {
            get<3>(temp[l]) += smaller_after;
            v[i++] = temp[l++];
        }
        while(r < e) {
            get<2>(temp[r]) += smaller_before;
            v[i++] = temp[r++];
        }
    }
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        temp.resize(n);
        temp_beg = temp.begin();
        v.reserve(n);
        for(int i = 0; i < n; ++i)
            v.emplace_back(i, rating[i], 0, 0);
        v_beg = v.begin();
        helper(0, n);
        int ret = 0;
        for(const auto &t : v) {
            int i = get<0>(t), smaller_before = get<2>(t), smaller_after = get<3>(t);
            ret += smaller_before * (n - i - 1 - smaller_after) + (i - smaller_before) * smaller_after;
        }
        return ret;
    }
};
