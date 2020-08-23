class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bitset<128> b;
        for(char c : J)
            b.set(c);
        int ret = 0;
        for(char c : S)
            ret += b[c];
        return ret;
    }
};
