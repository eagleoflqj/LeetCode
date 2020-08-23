class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ret;
        int maxCandy = *max_element(candies.begin(), candies.end());
        transform(candies.begin(), candies.end(), back_inserter(ret),
            [=](int i){ return i + extraCandies >= maxCandy; });
        return ret;
    }
};
