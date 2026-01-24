class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = n-1; i >= 0; --i){
            for(int j = m-1; j >= 0; --j){
                if(i == n-1 && j == m-1) continue;
                int opt1 = INT_MAX, opt2 = INT_MAX;
                if(i+1 < n){
                    opt1 = grid[i+1][j];
                }
                if(j+1 < m){
                    opt2 = grid[i][j+1];
                }
                grid[i][j] += min(opt1,opt2);
            }
        }
        return grid[0][0];
    }
};