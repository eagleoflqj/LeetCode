class Solution {
public:
    int trap(vector<int>& height) {
        stack<pair<int, int>> stk;
        int n = height.size(), ret = 0;
        for(int i = 0; i < n; ++i) {
            pair<int, int> p;
            int h = height[i], last_h = 0;
            while(!stk.empty() && (p = stk.top()).second <= h) {
                ret += (i - p.first - 1) * (p.second - last_h);
                last_h = p.second;
                stk.pop();
            }
            if(!stk.empty())
                ret += (i - p.first - 1) * (h - last_h);
            stk.emplace(i, height[i]);
        }
        return ret;
    }
};
