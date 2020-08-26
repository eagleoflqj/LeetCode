class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        const static vector<string> morseMap = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s;
        for(const auto &str : words) {
            string code;
            for(auto c : str)
                code += morseMap[c - 'a'];
            s.insert(move(code));
        }
        return s.size();
    }
};
