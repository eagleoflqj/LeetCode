class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ret{0};
        int lb = 0, ub = 0;
        for(char c : S)
            ret.push_back(c == 'I' ? ++ub : --lb);
        if(lb)
            transform(ret.begin(), ret.end(), ret.begin(), [lb](int i) { return i - lb; });
        return ret;
    }
};
