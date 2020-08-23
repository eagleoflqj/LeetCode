class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        while(n) {
            div_t d = div(n, 10);
            product *= d.rem;
            sum += d.rem;
            n = d.quot;
        }
        return product - sum;
    }
};
