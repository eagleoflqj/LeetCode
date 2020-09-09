class Solution {
public:
    int search(vector<int>& nums, int target) {
        int b = 0, e = nums.size() - 1;
        if(nums[b] > nums[e]) {
            while(e - b > 1) {
                int m = (b + e) >> 1;
                if(nums[m] > nums[b])
                    b = m;
                else
                    e = m;
            }
            if(target < nums[e] || target > nums[b])
                return -1;
            if(target >= nums[0]) {
                e = b;
                b = 0;
            } else {
                b = e;
                e = nums.size() - 1;
            }
        }
        while(b <= e) {
            int m = (b + e) >> 1;
            if(target > nums[m])
                b = m + 1;
            else if (target < nums[m])
                e = m - 1;
            else
                return m;
        }
        return -1;
    }
};
