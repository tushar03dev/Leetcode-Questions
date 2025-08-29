class Solution {
public:
    int solve(vector<vector<int>>& grid,int row, int col, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();        
        if (row == m - 1 && col == n - 1) return grid[row][col];

        if (row >= m || col >= n) return INT_MAX;

        if(dp[row][col] != -1) return dp[row][col];

        int right = solve(grid, row + 1, col,dp);
        int down = solve(grid, row, col + 1,dp);

        int best = min(right,down);
        if(best == INT_MAX){
            dp[row][col] = INT_MAX;
             return dp[row][col];
        }
        dp[row][col] = grid[row][col] + best;
        return dp[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = 0;
        int col = 0;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        int ans = solve(grid,row, col, dp);
        return ans;
    }
};
