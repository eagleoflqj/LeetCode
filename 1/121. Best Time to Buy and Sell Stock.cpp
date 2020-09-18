class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2)
            return 0;
        int m = prices[0], ret = 0;
        for(int i = 1; i < n; ++i)
            if(prices[i] < m)
                m = prices[i];
            else
                ret = max(ret, prices[i] - m);
        return ret;
    }
};
