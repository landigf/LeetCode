class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int res = 0;
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < m; ++c){
                if(r == 0 or c == 0) dp[r][c] = matrix[r][c] - '0';
                else if(matrix[r][c] == '1'){
                    dp[r][c] = min(min(dp[r - 1][c], dp[r][c - 1]), dp[r - 1][c - 1]) + 1;
                }
                res = max(res, dp[r][c]);
            }
        }
        return res * res;
    }
};