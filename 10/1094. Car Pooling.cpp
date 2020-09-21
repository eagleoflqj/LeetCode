class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        static const int UB = 1000;
        int count[UB + 1]{}, n = 0;
        for(const auto &trip : trips) {
            count[trip[1]] += trip[0];
            count[trip[2]] -= trip[0];
        }
        for(int i = 0; i <= UB; ++i)
            if((n += count[i]) > capacity)
                return false;
        return true;
    }
};
