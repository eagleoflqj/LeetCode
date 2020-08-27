template <unsigned SIZE>
class FenwickTree {
    static constexpr int LSB(unsigned i) { return i & -i; }
    int A[SIZE + 1]{};
public:
    void update(unsigned i, int k) {
        while(i <= SIZE) {
            A[i] += k;
            i += LSB(i);
        }
    }
    int partial_sum(unsigned i) {
        int sum = 0;
        while(i) {
            sum += A[i];
            i -= LSB(i);
        }
        return sum;
    }
};

namespace {
    constexpr int LB = 0;
    constexpr int UB = 1000;
}

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int left[UB - LB + 1]{};
        FenwickTree<UB - LB + 1> right;
        int n = arr.size();
        for(int k = 1; k < n; ++k)
            right.update(arr[k] - LB + 1, 1); // Fenwick Tree starts from 1
        int ret = 0;
        for(int j = 1; j < n - 1; ++j) {
            ++left[arr[j - 1] - LB];
            right.update(arr[j] - LB + 1, -1);
            int ai_lb = max(LB, arr[j] - a);
            int ai_ub = min(UB, arr[j] + a);
            int ak_lb = max(LB, arr[j] - b);
            int ak_ub = min(UB, arr[j] + b);
            for(int ai = ai_lb; ai <= ai_ub; ++ai) { // loop for every possible value of arr[i]
                if(!left[ai - LB]) // number of arr[i]s with the value 
                    continue;
                int lb = max(ai - c, ak_lb);
                int ub = min(ai + c, ak_ub);
                if(lb > ub) // check for empty range, otherwise ret may be negative
                    continue;
                ret += left[ai - LB] * (right.partial_sum(ub - LB + 1) - right.partial_sum(lb - LB));
            }
        }
        return ret;
    }
};
