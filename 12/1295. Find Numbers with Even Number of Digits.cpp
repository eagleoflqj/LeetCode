class Solution {
public:
    int findNumbers(vector<int>& nums) {
        return count_if(nums.begin(), nums.end(),
            [](int i) { return (int)log10(i) & 1; });
    }
};
