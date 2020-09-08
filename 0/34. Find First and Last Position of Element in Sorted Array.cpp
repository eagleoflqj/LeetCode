class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = 0, ub = nums.size(), m;
        while(lb < ub) { // [lb, ub)
            m = (lb + ub) >> 1;
            if(nums[m] < target)
                lb = m + 1;
            else if(nums[m] > target)
                ub = m;
            else
                break;
        }
        if(lb == ub)
            return {-1, -1};
        int b = m, e = m;
        while(lb < e) { // [lb, e], nums[e]=target
            m = (lb + e) >> 1;
            if(nums[m] < target)
                lb = m + 1;
            else
                e = m;
        }
        while(ub - b > 1) { // [b, ub), nums[b]=target
            m = (b + ub) >> 1;
            if(nums[m] > target)
                ub = m;
            else
                b = m;
        }
        return {lb, b};
    }
};
