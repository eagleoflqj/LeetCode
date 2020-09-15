class Solution {
public:
    int numSplits(string s) {
        bitset<26> left, right;
        int n = s.size(), cnt = 0, ret = 0;
        vector<int> count(n);
        left.set(s[0] - 'a');
        count[0] = 1;
        for(int i = 1; i < n; ++i) {
            if(left[s[i] -= 'a'])
                count[i] = count[i - 1];
            else {
                count[i] = count[i - 1] + 1;
                left.set(s[i]);
            }
        }
        for(int i = n - 1; i > 0; --i) {
            if(!right[s[i]]) {
                ++cnt;
                right.set(s[i]);
            }
            if(cnt == count[i - 1])
                ++ret;
            else if(cnt > count[i - 1])
                break;
        }
        return ret;
    }
};
