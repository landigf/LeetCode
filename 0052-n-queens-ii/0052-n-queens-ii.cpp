class Solution {
    vector<bool> cols, pDiag, nDiag;
    int d, res;

    void solve(int r){
        if(r == d) ++res;

        for(int c = 0; c < d; ++c){
            if(!(cols[c] && pDiag[r-c+d-1] && nDiag[r+c])) continue;
            
            cols[c] = pDiag[r-c+d-1] = nDiag[r+c] = false;

            solve(r+1);

            cols[c] = pDiag[r-c+d-1] = nDiag[r+c] = true;
        }
    }

public:
    int totalNQueens(int n) {
        d = n;
        res = 0;
        cols.assign(n, true);
        pDiag.assign(2*n-1, true);
        nDiag.assign(2*n-1, true);

        solve(0);


        return res;
    }
};