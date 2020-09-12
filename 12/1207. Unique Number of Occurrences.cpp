class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> st;
        for(int i : arr)
            ++m[i];
        for(auto p : m)
            if(!st.insert(p.second).second)
                return false;
        return true;
    }
};
