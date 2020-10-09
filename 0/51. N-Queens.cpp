class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> row(n, -1);
        vector<vector<string>> ret;
        vector<string> temp(n, string(n, '.'));
        int level = 0;
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
                ret.push_back(temp);
                for(int i = 0; i < n; ++i)
                    ret.back()[i][row[i]] = 'Q';
                --level;
            } else
                row[++level] = -1;
        } while(level >= 0);
        return ret;
    }
};
