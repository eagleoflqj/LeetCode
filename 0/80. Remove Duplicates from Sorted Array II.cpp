class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        int j = 0, last = nums[0], count = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] != last) {
                last = nums[i];
                count = 0;
            }
            if(++count <= 2)
                nums[j++] = nums[i];
        }
        return j;
    }
};
