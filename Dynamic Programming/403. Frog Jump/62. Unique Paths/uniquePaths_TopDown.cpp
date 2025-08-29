class Solution {
public:
    int solve(int m, int n, int row, int col,  vector<vector<int>>& dp){
        if(m-1 == row && n-1 == col) return 1;
        if(row >= m || col >= n) return 0;

        if(dp[row][col] != -1) return dp[row][col];

        dp[row][col] = solve(m,n,row+1, col, dp) + solve(m,n,row,col+1,dp); 
        return dp[row][col];
    }
    int uniquePaths(int m, int n) {
        int row = 0;
        int col = 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans = solve(m,n, row, col,dp);
        return ans;
    }
};
