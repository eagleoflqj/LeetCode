class Solution {
public:
    int kthFactor(int n, int k) {
        if(k == 1)
            return 1;
        vector<int> factors{1};
        int i = 2;
        while(i * i < n) {
            if(!(n % i)) {
                if(k == factors.size() + 1)
                    return i;
                factors.push_back(i);
            }
            ++i;
        }
        int sz = factors.size();
        if(i * i == n) {
            if(k == sz + 1)
                return i;
            return k > (sz << 1) + 1 ? -1 : n / factors[(sz << 1) + 1 - k];
        }
        return k > (sz << 1) ? -1 : n / factors[(sz << 1) - k];
    }
};
