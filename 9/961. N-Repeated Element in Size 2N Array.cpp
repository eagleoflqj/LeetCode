class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> s;
        for(auto i : A)
            if(!s.insert(i).second)
                return i;
        return 0;
    }
};
