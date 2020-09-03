class Solution {
    static inline int64_t getBucket(int64_t i, int64_t t) {
        return (i - INT_MIN) / (t + 1);
    }
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0 || k <= 0)
            return false;
        unordered_map<int64_t, int64_t> m;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int64_t bucket = getBucket(nums[i], t);
            auto iter = m.find(bucket), e = m.end();
            if(iter != e)
                return true;
            if((iter = m.find(bucket - 1)) != e && iter->second >= (int64_t)nums[i] - t)
                return true;
            if((iter = m.find(bucket + 1)) != e && iter->second <= (int64_t)nums[i] + t)
                return true;
            m[bucket] = nums[i]; // no override occurs
            if(i >= k)
                m.erase(getBucket(nums[i - k], t));
        }
        return false;
    }
};
