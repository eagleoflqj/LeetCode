class Solution {
public:
    bool isNumber(string s) {
        static const regex r("\\s*(\\+|-)?(\\d+(\\.\\d*)?|\\.\\d+)(e(\\+|-)?\\d+)?\\s*");
        return regex_match(s, r);
    }
};
