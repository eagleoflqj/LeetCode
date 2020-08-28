class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stk;
        int n = prices.size();
        for(int i = 0; i < n; ++i) {
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
