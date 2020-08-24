class Solution {
public:
    vector<int> baseline(vector<int>& nums, vector<int>& index, int) {
        int n = nums.size();
        vector<int> ret;
        ret.reserve(n);
        for(int i = 0; i < n; ++i)
            ret.insert(ret.begin() + index[i], nums[i]);
        return ret;
    }
    
    using Vec = vector<pair<int, int>>;
    Vec helper(Vec v) {
        int n = v.size();
        if(n < 2)
            return v;
        int m = n >> 1;
        auto b = v.begin();
        Vec left = helper(Vec(b, b + m)); // final positions if it's the rightmost subvector
        Vec right = helper(Vec(b + m, v.end()));
        int count = 0; // after inserting the head of the remaining of right, how many steps the remaining of left should move
        auto li = left.begin(), le = left.end();
        auto ri = right.begin(), re = right.end();
        while(li != le && ri != re) {
            if(li->second + count >= ri->second) { // ri pushes li
                ++count; // all numbers after li is affected
                *b++ = *ri++;
            } else { // no more ri pushes li, its position is determined
                li->second += count;
                *b++ = *li++;
            }
        }
        while(li != le) {
            li->second += count;
            *b++ = *li++;
        }
        while(ri != re) {
            *b++ = *ri++;
        }
        return v;
    }
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        Vec v;
        int n = nums.size();
        v.reserve(n);
        for(int i = 0; i < n; ++i)
            v.emplace_back(i, index[i]);
        v = helper(move(v));
        vector<int> ret(n);
        for(const auto &t : v)
            ret[t.second] = nums[t.first];
        return ret;
    }
};
