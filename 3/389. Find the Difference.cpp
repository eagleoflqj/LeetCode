class Solution {
public:
    char findTheDifference(string s, string t) {
        int count[26]{};
        for(char c : t)
            ++count[c - 'a'];
        for(char c : s)
            --count[c - 'a'];
        for(int i = 0; i < 26; ++i)
            if(count[i])
                return 'a' + i;
        return 0;
    }
};
