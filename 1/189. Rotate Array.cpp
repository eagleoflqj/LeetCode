class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        auto b = nums.begin(), e = nums.end(), m = e - k;
        reverse(b, m);
        reverse(m, e);
        reverse(b, e);
    }
};
