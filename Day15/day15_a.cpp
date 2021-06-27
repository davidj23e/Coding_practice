class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size(), out = INT_MAX;
        for(int row = 0; row < R; row++)
        {
            for(int col = 0; col < C; col++)
            {
                int a = (row - 1 > -1 && col - 1 > -1) ? matrix[row-1][col - 1] : INT_MAX;
                int b = (row - 1 > -1) ? matrix[row-1][col] : INT_MAX;
                int c = (row - 1 > -1 && col + 1 < C ) ? matrix[row-1][col + 1] : INT_MAX;
                int elem = min(a, min(b, c));
                matrix[row][col] += (elem > 100) ? 0 : elem;
                if(row == R-1)
                    out = min(out, matrix[row][col]);
            }

        }
        return out;
    }
};