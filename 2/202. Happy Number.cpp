class Solution {
    static constexpr int UB = 163;
    static int f(int x) {
        int t = 0;
        do {
            div_t d = div(x, 10);
            t += d.rem * d.rem;
            x = d.quot;
        } while(x);
        return t;
    }
    static void precompute() {
        int status[UB]{};
        for(int i = 1; i < UB; ++i) {
            if(status[i])
                continue;
            unordered_set<int> st{i};
            int j = i;
            do {
                j = f(j);
            } while(j != 1 && !status[j] && st.insert(j).second);
            for(int t : st)
                status[t] = j == 1 || status[j] == 1 ? 1 : 2;
        }
        for(int i = 0; i < UB; ++i)
            cout << (status[i] == 1) << ',' << ((i + 1) % 10 ? ' ' : '\n');
    }
public:
    bool isHappy(int n) {
        static const bool happy[UB] = {
            0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
            1, 0, 0, 1, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
            0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            0, 0, 1, 0, 0, 0, 1, 0, 0, 0,
            0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
            1, 0, 0, 1, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 0, 0, 1, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0
        };
        while(n >= UB)
            n = f(n);
        return happy[n];
    }
};
