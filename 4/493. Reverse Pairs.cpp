class Solution {
    vector<int> temp;
    vector<int>::iterator beg;
    int helper(vector<int> &v, int b, int e) {
        if(e - b < 2)
            return 0;
        int m = (b + e) >> 1;
        int ret = helper(v, b, m) + helper(v, m, e);
        copy(v.begin() + b, v.begin() + e, beg + b);
        int l = b, r = m;
        while(l < m && r < e)
            if(temp[l] <= 2LL * temp[r])
                ++l;
            else {
                ++r;
                ret += m - l;
            }
        merge(beg + b, beg + m, beg + m, beg + e, v.begin() + b);
        return ret;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        temp.resize(n);
        beg = temp.begin();
        return helper(nums, 0, n);
    }
};
