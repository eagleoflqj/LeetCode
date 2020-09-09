class Solution {
    int getSubversion(const string &s, int &i) {
        ++i;
        int ret = 0;
        do {
            ret = ret * 10 + s[i] - '0';
        } while(isdigit(s[++i]));
        return ret;
    }
public:
    int compareVersion(string version1, string version2) {
        int i = -1, j = -1;
        do {
            int v1 = getSubversion(version1, i), v2 = getSubversion(version2, j);
            if(v1 != v2)
                return v1 > v2 ? 1 : -1;
        } while(version1[i] && version2[j]);
        if(!version1[i]) {
            while(version2[j])
                if(getSubversion(version2, j))
                    return -1;
            return 0;
        }
        do {
            if(getSubversion(version1, i))
                return 1;
        } while(version1[i]);
        return 0;
    }
};
