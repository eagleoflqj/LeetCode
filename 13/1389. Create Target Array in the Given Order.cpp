class Solution {
    using Vec = vector<pair<int, int>>;
    Vec v, temp;
    Vec::iterator v_beg, temp_beg;
    void helper(int b, int e) {
        if(e - b < 2)
            return;
        int m = (b + e) >> 1;
        helper(b, m); // final positions if [b, m) is the rightmost subvector
        helper(m, e);
        copy(v_beg + b, v_beg + e, temp_beg + b);
        int count = 0; // after inserting the head of the remaining of right, how many steps the remaining of left should move
        int i = b, l = b, r = m;
        while(l < m && r < e) {
            if(temp[l].second + count >= temp[r].second) { // ri pushes li
                ++count; // all numbers after li is affected
                v[i++] = temp[r++];
            } else { // no more ri pushes li, its position is determined
                temp[l].second += count;
                v[i++] = temp[l++];
            }
        }
        while(l < m) {
            temp[l].second += count;
            v[i++] = temp[l++];
        }
        copy(temp_beg + r, temp_beg + e, v_beg + r);
    }
public:
    vector<int> baseline(vector<int>& nums, vector<int>& index, int) {
        int n = nums.size();
        vector<int> ret;
        ret.reserve(n);
        for(int i = 0; i < n; ++i)
            ret.insert(ret.begin() + index[i], nums[i]);
        return ret;
    }
    
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        temp.resize(n);
        temp_beg = temp.begin();
        v.reserve(n);
        for(int i = 0; i < n; ++i)
            v.emplace_back(i, index[i]);
        v_beg = v.begin();
        helper(0, n);
        vector<int> ret(n);
        for(const auto &t : v)
            ret[t.second] = nums[t.first];
        return ret;
    }
};
