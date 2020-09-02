class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int depth = 0, l = label;
        while((l >>= 1))
            ++depth;
        vector<int> ret(depth + 1);
        while(depth) {
            ret[depth] = label;
            if(depth & 1)
                label = ((3 << depth) - label - 1) >> 1;
            else
                label = (3 << (depth - 1)) - (label >> 1) - 1;
            --depth;
        }
        ret[0] = 1;
        return ret;
    }
};
