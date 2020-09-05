class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret{0};
        for(int i = 1; i <= num; ++i)
            ret.push_back(ret[i & (i - 1)] + 1);
        return ret;
    }
};
