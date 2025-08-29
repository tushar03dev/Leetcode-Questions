class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    
        vector<vector<int>> dp(triangle.size()+1,
                               vector<int>(triangle.size()+1, 0));

        for (int row = triangle.size()-1; row >= 0; row--) {
            for (int col = row; col >= 0; col--) {
                int option1 =
                    triangle[row][col] + dp[row + 1][col];
                int option2 =
                    triangle[row][col] + dp[row + 1][col + 1];

                dp[row][col] = min(option1, option2);
            }
        }
        
        return dp[0][0];
    }
};
