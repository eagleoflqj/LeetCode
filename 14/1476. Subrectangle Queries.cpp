class SubrectangleQueries {
    vector<vector<int>> rectangle;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : rectangle(rectangle) {}
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i = row1; i <= row2; ++i) {
            auto &row = rectangle[i];
            for(int j = col1; j <= col2; ++j)
                row[j] = newValue;
        }
    }
    
    int getValue(int row, int col) {
        return rectangle[row][col];
    }
};
