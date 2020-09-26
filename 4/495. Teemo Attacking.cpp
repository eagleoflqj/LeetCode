class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ret = duration, n = timeSeries.size();
        if(!n)
            return 0;
        for(int i = 1; i < n; ++i)
            ret += min(timeSeries[i] - timeSeries[i - 1], duration);
        return ret;
    }
};
