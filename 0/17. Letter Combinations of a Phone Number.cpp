class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static const string alphabet[10]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(digits.empty())
            return vector<string>();
        vector<string> ret{""}, temp;
        for(char d : digits) {
            temp = move(ret);
            ret.clear();
            for(const string &s : temp)
                for(char c : alphabet[d - '0'])
                    ret.push_back(s + c);
        }
        return ret;
    }
};
