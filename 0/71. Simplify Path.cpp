class Solution {
public:
    string simplifyPath(string path) {
        vector<string> canonical;
        int n = path.size();
        bool slash = true;
        for(int i = 1; i < n; ++i) {
            if(path[i] == '/') {
                slash = true;
                continue;
            }
            if(slash && path[i] == '.') {
                if(!path[i + 1] || path[i + 1] == '/')
                    continue;
                if(path[i + 1] == '.' && (!path[i + 2] || path[i + 2] == '/')) {
                    ++i;
                    if(!canonical.empty())
                        canonical.pop_back();
                    continue;
                }
            }
            if(slash) {
                slash = false;
                canonical.push_back("");
            }
            canonical.back() += path[i];
        }
        string ret;
        for(const string &s : canonical)
            ret += "/" + s;
        return ret.size() ? ret : "/";
    }
};
