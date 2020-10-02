class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        while(n--) {
            if(digits[n] < 9) {
                ++digits[n];
                return digits;
            }
            digits[n] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
