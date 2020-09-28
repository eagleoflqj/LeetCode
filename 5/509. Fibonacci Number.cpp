class Solution {
    static constexpr int UB = 30;
    static void precompute() {
        int f0 = 0, f1 = 1;
        cout << f0 << ", " << f1;
        for(int i = 2; i <= UB; ++i) {
            int f2 = f0 + f1;
            cout << ',' << (i % 10 ? ' ' : '\n') << f2;
            f0 = f1;
            f1 = f2;
        }
    }
public:
    int fib(int N) {
        static const int f[UB + 1] {
            0, 1, 1, 2, 3, 5, 8, 13, 21, 34,
            55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181,
            6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229,
            832040
        };
        return f[N];
    }
};
