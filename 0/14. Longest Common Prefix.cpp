class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto b = strs.begin(), e = strs.end();
        if(b == e)
            return "";
        size_t min_length = string::npos;
        for_each(b, e, [&min_length](const string &s) { min_length = min(min_length, s.size()); });
        for(int i = 0; i < min_length; ++i) {
            char c = (*b)[i];
            for(auto iter = b + 1; iter != e; ++iter)
                if((*iter)[i] != c)
                    return iter->substr(0, i);
        }
        return b->substr(0, min_length);
    }
};
