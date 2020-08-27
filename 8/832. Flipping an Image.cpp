class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(auto &row : A) {
            int i = 0, j = row.size() - 1;
            while(i < j) {
                int t = row[i];
                row[i] = !row[j];
                row[j] = !t;
                ++i;
                --j;
            }
            if(i == j)
                row[i] = !row[i];
        }
        return A;
    }
};
