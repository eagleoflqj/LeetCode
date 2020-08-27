class Solution {
public:
    string defangIPaddr(string address) {
        static const regex r("\\.");
        return regex_replace(address, r, "[.]");
    }
};
