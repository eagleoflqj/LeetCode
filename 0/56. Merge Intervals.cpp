class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(!n)
            return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret{move(intervals[0])};
        for(int i = 1; i < n; ++i) {
            auto &last = ret.back();
            if(intervals[i][0] <= last[1])
                last[1] = max(last[1], intervals[i][1]);
            else
                ret.push_back(move(intervals[i]));
        }
        return ret;
    }
};
