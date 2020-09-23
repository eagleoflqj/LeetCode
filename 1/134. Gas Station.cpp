class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), sum = 0, m = 0, ret = -1;
        for(int i = 0; i < n; ++i) {
            sum += gas[i] - cost[i];
            if(sum < m) {
                m = sum;
                ret = i;
            }
        }
        return sum < 0 ? -1 : (ret + 1) % n;
    }
};
