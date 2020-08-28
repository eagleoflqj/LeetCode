class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last_position[26];
        int n = S.size();
        for(int i = 0; i < n; ++i) {
            S[i] -= 'a';
            last_position[S[i]] = i;
        }
        vector<int> ret;
        int i = 0, lb, ub;
        do {
            lb = i;
            ub = last_position[S[i++]];
            while(i <= ub)
                ub = max(ub, last_position[S[i++]]);
            ret.push_back(i - lb);
        } while(i < n);
        return ret;
    }
};
