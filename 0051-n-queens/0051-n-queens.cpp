class Solution {
    vector<string> board;
    vector<vector<string>> res;
    vector<bool> cols, pDiag, nDiag;
    int d;

    void solve(int r){
        if(r == d) res.push_back(board);

        for(int c = 0; c < d; ++c){
            if(!(cols[c] && pDiag[r-c+d-1] && nDiag[r+c])) continue;
            
            board[r][c] = 'Q';
            cols[c] = pDiag[r-c+d-1] = nDiag[r+c] = false;

            solve(r+1);

            board[r][c] = '.';
            cols[c] = pDiag[r-c+d-1] = nDiag[r+c] = true;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        d = n;
        res.clear();
        board.assign(n, string(n, '.'));
        cols.assign(n, true);
        pDiag.assign(2*n-1, true);
        nDiag.assign(2*n-1, true);

        solve(0);


        return res;
    }
};