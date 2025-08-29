class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1) return 0; 
        
        vector<vector<long long>> dp(m+1, vector<long long>(n+1,0));
        dp[m-1][n-1] = 1;

        for(int row = m-1; row >= 0; row--){
            for(int col = n-1; col >= 0; col--){
                if(row == m-1 && col == n-1) continue;
                if(obstacleGrid[row][col] == 1){
                     dp[row][col] = 0;
                     continue;
                }

                dp[row][col] = dp[row+1][col] + dp[row][col+1];
            }
        }

        return (int) dp[0][0];
    }
};
