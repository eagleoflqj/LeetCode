class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> index(n), ret;
        for(int i = 0; i < n; ++i)
            index[arr[i] - 1] = i;
        for(int i = n - 1; i > 0; --i)
            if(index[i] != i) { // AxBy
                ret.push_back(index[i] + 1); // xA'By
                ret.push_back(i + 1); // yB'Ax
                int d = i - index[i];
                ret.push_back(d--); // ByAx
                if(d)
                    ret.push_back(d); // B'yAx
                ret.push_back(i); // A'yBx
                if(index[i])
                    ret.push_back(index[i]); // AyBx
                arr[index[i]] = arr[i];
                index[arr[i] - 1] = index[i];
            }
        return ret;
    }
};
