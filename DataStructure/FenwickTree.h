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
