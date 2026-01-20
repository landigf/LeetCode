class Solution {
    int n;
    int m;
    int help(const vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo){
        if(i == n-1 && j == m-1) return 1;
        if(memo[i][j] != -1) return memo[i][j];
        int opt1 = 0, opt2 = 0;
        if(j+1 < m && matrix[i][j+1] != 1) opt1 = help(matrix,i,j+1,memo);
        if(i+1 < n && matrix[i+1][j] != 1) opt2 = help(matrix,i+1,j,memo);
        memo[i][j] = opt1 + opt2;
        return memo[i][j];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;
        vector<vector<int>> memo(n, vector<int>(m,-1));
        return help(obstacleGrid, 0, 0, memo);
        /*
        vector<vector<int>> dp(n, vector<int>(m,-1));
        dp[n-1][m-1] = 1;
        for(int i = n-1; i >= 0; --i){
            for(int j = m-1; j >= 0; --j){
                if(i == n-1 && j == m-1) continue;
                int opt1 = 0, opt2 = 0;
                if(j+1 < m && matrix[i][j+1] != 1) opt1 = help(matrix,i,j+1);
                if(i+1 < n && matrix[i+1][j] != 1) opt2 = help(matrix,i+1,j);
                return opt1 + opt2;
                if(i+1 < n)
            }
        }
        */
    }
};