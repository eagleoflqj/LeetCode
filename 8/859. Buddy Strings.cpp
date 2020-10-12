class Solution {
public:
    bool buddyStrings(string A, string B) {
        array<int, 26> a{};
        int m = A.size(), n = B.size(), diff = 0, diff_index[2];
        bool twice = false;
        if(m != n)
            return false;
        while(n--) {
            if(A[n] != B[n]) {
                if(diff == 2)
                    return false;
                diff_index[diff++] = n;
            }
            if(++a[A[n] - 'a'] == 2)
                twice = true;
        }
        return (diff == 2 && A[diff_index[0]] == B[diff_index[1]] && A[diff_index[1]] == B[diff_index[0]]) || (!diff && twice);
    }
};
