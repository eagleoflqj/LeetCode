class Solution {
public:
    string defangIPaddr(string address) {
        regex r("\\.");
        return regex_replace(address, r, "[.]");
    }
};
