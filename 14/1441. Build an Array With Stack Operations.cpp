class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ret;
        n = 1;
        for(int i : target) {
            while(n < i) {
                ret.push_back("Push");
                ret.push_back("Pop");
                ++n;
            }
            ret.push_back("Push");
            ++n;
        }
        return ret;
    }
};
