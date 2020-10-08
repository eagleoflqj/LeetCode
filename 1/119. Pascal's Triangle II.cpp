class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> last{1}, current{1};
        for(int i = 1; i <= rowIndex; ++i) {
            swap(last, current);
            current.resize(i + 1);
            current[i] = 1;
            for(int j = 1; j < i; ++j)
                current[j] = last[j - 1] + last[j];
        }
        return current;
    }
};
