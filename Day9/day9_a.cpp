class NumMatrix {
public:
    vector<vector<int>> M;
    NumMatrix(vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size();
        cout << R << " " << C << endl;
        for(int i=0; i < R; i++)
        {
            for(int j=0; j < C; j++)
            {
                matrix[i][j] += ((j-1 < 0) ? 0: matrix[i][j-1]);
            }
            for(int j=0; j < C; j++)
            {
                matrix[i][j] += ((i-1 < 0) ? 0: matrix[i-1][j]);
            }
        }
        M = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        sum += M[row2][col2];
        sum += (row1 - 1 < 0 || col1 - 1 < 0) ? 0 : M[row1-1][col1-1];
        sum -= (col1 - 1 < 0) ? 0 : M[row2][col1-1];
        sum -= (row1 - 1 < 0) ? 0 : M[row1-1][col2];

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */