class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        static const int LB = 1, UB = 1000;
        vector<vector<int>> ret;
        int x = UB, y = LB;
        while(x >= LB && y <= UB) {
            int f = customfunction.f(x, y);
            if(f > z)
                --x;
            else if(f < z)
                ++y;
            else
                ret.push_back({x--, y++});
        }
        return ret;
    }
};
