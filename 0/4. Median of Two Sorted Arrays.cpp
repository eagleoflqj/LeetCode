class Solution {
    static inline double median(const vector<int> &v, int b, int e) {
        int m = (b + e) >> 1;
        if((e - b) & 1)
            return v[m];
        return (v[m - 1] + v[m]) * 0.5;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int b1 = 0, b2 = 0;
        int e1 = nums1.size(), e2 = nums2.size();
        vector<int> *p1 = &nums1, *p2 = &nums2;
        if(e1 > e2) { // let p1 be the shorter
            swap(e1, e2);
            swap(p1, p2);
        }
        double med2;
        while(med2 = median(*p2, b2, e2), e1 - b1 >= 3) {
            double med1 = median(*p1, b1, e1);
            if(med1 == med2)
                return med1;
            int h = (e1 - b1 - 1) >> 1; // for length 2n or 2n-1, n-1 can be safely excluded, so length>=3 to make progress
            if(med1 < med2) {
                b1 += h;
                e2 -= h;
            } else {
                e1 -= h;
                b2 += h;
            }
        }
        if(b1 == e1)
            return med2;
        if(e2 - b2 == 1) // implies e1 - b1 = 1
            return ((*p1)[b1] + med2) / 2;
        int m2 = (b2 + e2) >> 1;
        vector<int> temp{(*p1)[b1], (*p2)[m2 - 1], (*p2)[m2]};
        if(e1 - b1 == 2) {
            temp.push_back((*p1)[b1 + 1]);
            if(e2 - b2 > 2) {
                temp.push_back((*p2)[m2 + 1]);
                if(!((e2 - b2) & 1))
                    temp.push_back((*p2)[m2 - 2]);
            }
        } else if((e2 - b2) & 1)
            temp.push_back((*p2)[m2 + 1]);
        sort(temp.begin(), temp.end());
        return median(temp, 0, temp.size());
    }
};
