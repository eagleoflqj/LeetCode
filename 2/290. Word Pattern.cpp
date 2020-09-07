class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream iss(str);
        string a[26]{};
        unordered_set<string> st;
        for(char c : pattern) {
            c -= 'a';
            string s;
            iss >> s;
            if(s.empty())
                return false;
            if(a[c].empty()) {
                if(st.find(s) != st.end())
                    return false;
                st.insert(s);
                a[c] = move(s);
            }
            else if(a[c] != s)
                return false;
        }
        return iss.eof();
    }
};
