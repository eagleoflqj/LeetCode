class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        auto p = minmax_element(arr.begin(), arr.end());
        int m = *p.first, M = *p.second;
        if(m == M)
            return true;
        div_t d = div(M - m, arr.size() - 1);
        if(d.rem)
            return false;
        M = m;
        for(int current : arr) {
            while(current != M) {
                div_t index = div(current - m, d.quot);
                if(index.rem || arr[index.quot] == current)
                    return false;
                swap(current, arr[index.quot]);
            }
            M += d.quot;
        }
        return true;
    }
};
