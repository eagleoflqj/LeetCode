class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        vector<char> v;
        while(x) {
            div_t d = div(x, 10);
            v.push_back(d.rem);
            x = d.quot;
        }
        for(int i = 0, j = v.size() - 1; i < j; ++i, --j)
            if(v[i] != v[j])
                return false;
        return true;
    }
};
