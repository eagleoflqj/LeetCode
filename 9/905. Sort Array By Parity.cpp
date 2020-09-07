class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ret(A.size());
        auto b = ret.begin();
        auto rb = ret.rbegin();
        for(auto i : A)
            if(i & 1)
                *rb++ = i;
            else
                *b++ = i;
        return ret;
    }
};
