class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<long long>> dp(n, vector<long long>(m,-1));
        dp[n-1][m-1] = 1;
        for(int i = n-1; i >= 0; --i){
            for(int j = m-1; j >= 0; --j){
                if(i == n-1 && j == m-1) continue;
                long long opt1 = 0, opt2 = 0;
                if(i+1 < n) opt1 = dp[i+1][j];
                if(j+1 < m) opt2 = dp[i][j+1];
                dp[i][j] = opt1 + opt2;
            }
        }
        return dp[0][0];
    }
};