class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stk;
        stk.push(0);
        int n = prices.size();
        for(int i = 1; i < n; ++i) {
            while(!stk.empty()) {
                auto p = stk.top();
                if(prices[p] < prices[i])
                    break;
                prices[p] -= prices[i];
                stk.pop();
            }
            stk.push(i);
        }
        return prices;
    }
};
