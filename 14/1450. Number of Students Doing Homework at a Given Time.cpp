class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        int ret = 0;
        for(int i = 0; i < n; ++i)
            if(startTime[i] <= queryTime && queryTime <= endTime[i])
                ++ret;
        return ret;
    }
};
