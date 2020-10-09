class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> stk;
        for(int i : nums) {
            int lb = stk.empty() || i < stk.top().first ? i : stk.top().first;
            while(!stk.empty() && i > stk.top().first) {
                if(i < stk.top().second)
                    return true;
                stk.pop();
            }
            stk.emplace(lb, i);
        }
        return false;
    }
};
