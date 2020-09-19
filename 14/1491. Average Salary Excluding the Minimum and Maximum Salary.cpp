class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size(), m = INT_MAX, M = INT_MIN, sum = 0;
        for(int i : salary) {
            sum += i;
            m = min(m, i);
            M = max(M, i);
        }
        return (double)(sum - M - m) / (n - 2);
    }
};
