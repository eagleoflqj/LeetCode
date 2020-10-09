class Solution {
public:
    int totalNQueens(int n) {
        vector<int> row(n, -1);
        int level = 0, ret = 0;
        do {
            if(++row[level] == n) {
                --level;
                continue;
            }
            bool valid = true;
            for(int i = 0; i < level; ++i)
                if(row[i] == row[level] || abs(row[i] - row[level]) == level - i) {
                    valid = false;
                    break;
                }
            if(!valid)
                continue;
            if(level == n - 1) {
                ++ret;
                --level;
            } else
                row[++level] = -1;
        } while(level >= 0);
        return ret;
    }
};
