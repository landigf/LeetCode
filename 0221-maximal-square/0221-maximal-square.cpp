class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector <vector <int> > table (row, vector <int> (col, 0));
        int maxSide = 0;
        for(int r = 0; r < row; ++r){
            for(int c = 0; c < col; ++c){
                if(r == 0 or c == 0) table[r][c] = matrix[r][c] - '0';
                else if(matrix[r][c] == '1'){
                    table[r][c] = min(min(table[r - 1][c], table[r][c - 1]), table[r - 1][c - 1]) + 1;
                }
                maxSide = max(maxSide, table[r][c]);
            }
        }
        return maxSide * maxSide;
    }
};