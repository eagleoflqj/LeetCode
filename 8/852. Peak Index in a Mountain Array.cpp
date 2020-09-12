class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int b = 0, e = arr.size() - 1;
        while(e - b > 2) {
            int m = (b + e + 1) >> 1;
            if(arr[m] > arr[m - 1])
                b = m - 1;
            else
                e = m;
        }
        return b + 1;
    }
};
