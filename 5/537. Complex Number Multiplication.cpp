class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ra, ia, rb, ib;
        char c;
        istringstream(a) >> ra >> c >> ia;
        istringstream(b) >> rb >> c >> ib;
        ostringstream oss;
        oss << (ra * rb - ia * ib) << '+' << (ra * ib + ia * rb) << 'i';
        return oss.str();
    }
};
