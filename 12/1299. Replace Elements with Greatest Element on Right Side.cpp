class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int m = -1;
        for(auto b = arr.rbegin(); b != arr.rend(); ++b) {
            int n = max(*b, m);
            *b = m;
            m = n;
        }
        return arr;
    }
};
