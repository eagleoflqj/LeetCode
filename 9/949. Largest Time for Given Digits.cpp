class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.rbegin(), A.rend());
        vector<int> B(A);
        do {
            int h = B[0] * 10 + B[1];
            int m = B[2] * 10 + B[3];
            if(h < 24 && m < 60) {
                ostringstream oss;
                oss <<  setfill('0') << setw(2) << h << ':' << setw(2) << m;
                return oss.str();
            }
            prev_permutation(B.begin(), B.end());
        } while (B != A);
        return "";
    }
};
