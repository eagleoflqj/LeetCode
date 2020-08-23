class Solution {
public:
    using Vec = vector<tuple<int, int, int>>;
    Vec helper(Vec v) {
        int n = v.size();
        if(n < 2)
            return v;
        int m = n >> 1;
        auto b = v.begin();
        Vec left = helper(Vec(b, b + m));
        Vec right = helper(Vec(b + m, v.end()));
        int count = 0;
        auto li = left.begin(), le = left.end();
        auto ri = right.begin(), re = right.end();
        while(li != le && ri != re) {
            if(get<1>(*li) > get<1>(*ri)) {
                ++count;
                *b++ = *ri++;
            } else {
                get<2>(*li) += count;
                *b++ = *li++;
            }
        }
        while(li != le) {
            get<2>(*li) += count;
            *b++ = *li++;
        }
        while(ri != re) {
            *b++ = *ri++;
        }
        return v;
    }
    vector<int> countSmaller(vector<int>& nums) {
        Vec v;
        int n = nums.size();
        v.reserve(n);
        for(int i = 0; i < n; ++i)
            v.emplace_back(i, nums[i], 0);
        v = helper(move(v));
        vector<int> ret(n);
        for(const auto &t : v)
            ret[get<0>(t)] = get<2>(t);
        return ret;
    }
};
