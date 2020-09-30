class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int j = arr1.size(), n2 = arr2.size();
        unordered_map<int, int> m;
        for(int i = 0; i < n2; ++i)
            m.emplace(arr2[i], i);
        auto e = m.end();
        vector<int> count(n2);
        for(int i = 0; i < j;) {
            auto iter = m.find(arr1[i]);
            if(iter == e)
                swap(arr1[i], arr1[--j]);
            else {
                ++count[iter->second];
                ++i;
            }
        }
        for(int i = 0, k = 0; k < n2; ++k)
            while(count[k]--)
                arr1[i++] = arr2[k];
        sort(arr1.begin() + j, arr1.end());
        return arr1;
    }
};
