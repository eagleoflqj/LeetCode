class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ret;
        int left = 0;
        for(char c : seq)
            ret.push_back((c == '(' ? left++ : --left) & 1);
        return ret;
    }
};
