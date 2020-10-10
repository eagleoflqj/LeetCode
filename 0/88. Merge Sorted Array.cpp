class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m-- + n--;
        while(l--)
            nums1[l] = m < 0 || (n >= 0 && nums1[m] < nums2[n]) ? nums2[n--] : nums1[m--];
    }
};
