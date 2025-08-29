class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        vector<vector<int>> dp(grid.size() + 1,
                               vector<int>(grid[0].size() + 1, INT_MAX));

        dp[grid.size() - 1][grid[0].size() - 1] =
            grid[grid.size() - 1][grid[0].size() - 1];

        for (int row = grid.size() - 1; row >= 0; row--) {
            for (int col = grid[0].size() - 1; col >= 0; col--) {

                if (row == grid.size() - 1 && col == grid[0].size()-1)
                    continue;
                int right = dp[row + 1][col];
                int down = dp[row][col + 1];

                int best = min(right, down);
                if (best == INT_MAX) {
                    dp[row][col] = INT_MAX;
                    continue;
                }
                dp[row][col] = grid[row][col] + best;
            }
        }
        return dp[0][0];
    }
};
