// The interval containing arr[i] has i+1/n-i choices for left/right end.
// Draw a (i+1)*(n-i) grid, black-and-white color it. The color of (0,0) appears ceil((i+1)*(n-i)/2) times.
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size(), sum = 0;
        for(int i = 0; i < n; ++i)
            sum += arr[i] * (((i + 1) * (n - i) + 1) >> 1);
        return sum;
    }
};
