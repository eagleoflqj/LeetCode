class Solution {
public:
    int heightChecker(vector<int>& heights) {
        static const int UB = 100, LB = 1;
        int count[UB - LB + 1]{}, ret = 0;
        for(int h : heights)
            ++count[h - LB];
        for(int h = LB, i = 0; h <= UB; ++h)
            for(int j = 0; j < count[h - LB]; ++j, ++i)
                if(heights[i] != h)
                    ++ret;
        return ret;
    }
};
