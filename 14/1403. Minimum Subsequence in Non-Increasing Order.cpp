class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        static constexpr int UB = 100;
        int count[UB + 1]{}, half = 0, sum = 0;
        for(int i : nums) {
            ++count[i];
            half += i;
        }
        half >>= 1;
        vector<int> ret;
        for(int i = UB; i > 0; --i)
            while(count[i]--) {
                ret.push_back(i);
                if((sum += i) > half)
                    goto out;
            }
    out:
        return ret;
    }
};
