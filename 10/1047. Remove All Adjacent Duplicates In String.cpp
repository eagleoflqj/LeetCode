class Solution {
public:
    string removeDuplicates(string S) {
        int i = 0, n = S.size();
        for(int j = 1; j < n; ++j)
            if(i < 0 || S[i] != S[j])
                S[++i] = S[j];
            else
                --i;
        return S.substr(0, i + 1);
    }
};
