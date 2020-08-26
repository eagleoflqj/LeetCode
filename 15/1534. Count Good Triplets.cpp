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
        FenwickTree<UB - LB + 1> left, right;
        int n = arr.size();
        for(int k = 1; k < n; ++k)
            right.update(arr[k] - LB + 1, 1); // Fenwick Tree starts from 1
        int ret = 0;
        for(int j = 1; j < n - 1; ++j) {
            left.update(arr[j - 1] - LB + 1, 1);
            right.update(arr[j] - LB + 1, -1);
            int ai_lb = max(LB, arr[j] - a);
            int ai_ub = min(UB, arr[j] + a);
            for(int ai = ai_lb; ai <= ai_ub; ++ai) { // loop for every possible value of arr[i]
                int count = left.partial_sum(ai - LB + 1) - left.partial_sum(ai - LB); // number of arr[i]s with the value 
                if(!count)
                    continue;
                int ak_lb = max(ai - c, arr[j] - b); // inequality for arr[k]
                int ak_ub = min(ai + c, arr[j] + b);
                if(ak_lb > ak_ub) // check for empty range, otherwise ret may be negative
                    continue;
                ak_lb = max(LB, ak_lb);
                ak_ub = min(UB, ak_ub);
                ret += count * (right.partial_sum(ak_ub - LB + 1) - right.partial_sum(ak_lb - LB));
            }
        }
        return ret;
    }
};
