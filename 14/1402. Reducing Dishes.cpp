class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());
        int ret = 0, sum = 0;
        for(auto b = satisfaction.begin(), e = satisfaction.end(); b != e; ++b) {
            sum += *b;
            if(sum > 0)
                ret += sum;
            else
                break;
        }
        return ret;
    }
};
