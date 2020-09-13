class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int b = newInterval[0], e = newInterval[1];
        bool inserted = false;
        for(const auto &interval : intervals) {
            if(inserted || b > interval[1])
                ret.push_back(interval);
            else if(e < interval[0]) {
                ret.push_back({b, e});
                ret.push_back(interval);
                inserted = true;
            } else {
                b = min(b, interval[0]);
                if(e <= interval[1]) {
                    ret.push_back({b, interval[1]});
                    inserted = true;
                }
            }
        }
        if(!inserted)
            ret.push_back({b, e});
        return ret;
    }
};
