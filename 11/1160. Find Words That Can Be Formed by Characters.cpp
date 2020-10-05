class Solution {
    static array<int, 26> helper(const string &s) {
        array<int, 26> ret{};
        for(char c : s)
            ++ret[c - 'a'];
        return ret;
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        auto arr = helper(chars);
        int ret = 0;
        for(const string &s : words) {
            auto a = helper(s);
            bool good = true;
            for(int i = 0; i < 26; ++i)
                if(a[i] > arr[i]) {
                    good = false;
                    break;
                }
            if(good)
                ret += s.size();
        }
        return ret;
    }
};
