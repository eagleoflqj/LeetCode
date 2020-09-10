class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        static constexpr int l = 3, n = l * l;
        bitset<n> column[n], sub[n];
        for(int i = 0; i < n; ++i) {
            bitset<n> row;
            for(int j = 0; j < n; ++j) {
                unsigned v = board[i][j] - '1';
                if(v >= n)
                    continue;
                int sub_index = i / l * l + j / l;
                if(row[v] || column[j][v] || sub[sub_index][v])
                    return false;
                row.set(v);
                column[j].set(v);
                sub[sub_index].set(v);
            }
        }
        return true;
    }
};
