class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ret(s.size(), ' ');
        int j = 0;
        for(auto i : indices)
            ret[i] = s[j++];
        return ret;
    }
};
