class Solution {
public:
    string sortString(string s) {
        map<char, int> m;
        for(char c : s)
            ++m[c];
        string ret;
        while(m.size()) {
            auto iter = m.begin();
            while(iter != m.end()) {
                ret += iter->first;
                if(--iter->second)
                    ++iter;
                else
                    iter = m.erase(iter);
            }
            auto riter = m.rbegin();
            while(riter != m.rend()) {
                ret += riter->first;
                if(--riter->second)
                    ++riter;
                else
                    riter = reverse_iterator<decltype(iter)>(m.erase(--riter.base()));
            }
        }
        return ret;
    }
};
