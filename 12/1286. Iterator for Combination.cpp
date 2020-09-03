class CombinationIterator {
    const string s;
    const int n;
    vector<bool> v;
    bool has;
public:
    CombinationIterator(string characters, int combinationLength) : s(characters), n(characters.size()), v(n), has(true) {
        fill_n(v.begin(), combinationLength, 1);
    }
    
    string next() {
        if(!has)
            return "";
        string ret;
        int last_1, last_0 = -1;
        for(int i = 0; i < n; ++i)
            if(v[i])
                ret += s[last_1 = i];
            else
                last_0 = i;
        if(last_1 == n - 1) {
            int to_move = last_0 - 1;
            while(to_move >= 0 && !v[to_move])
                --to_move;
            if(to_move < 0)
                has = false;
            else {
                v[to_move] = 0;
                v[++to_move] = 1;
                fill_n(v.begin() + last_0 + 1, last_1 - last_0, 0);
                fill_n(v.begin() + to_move + 1, last_1 - last_0, 1);
            }
        } else {
            v[last_1] = 0;
            v[last_1 + 1] = 1;
        }
        return ret;
    }
    
    bool hasNext() {
        return has;
    }
};
