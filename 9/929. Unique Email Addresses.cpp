class Solution {
    static string normalize(const string &s) {
        string ret;
        int n = s.size(), i = 0;
        while(s[i] != '+' && s[i] != '@') {
            if(s[i] != '.')
                ret += s[i];
            ++i;
        }
        while(s[i] != '@')
            ++i;
        return ret + s.substr(i);
    }
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(const auto &email : emails)
            st.insert(normalize(email));
        return st.size();
    }
};
