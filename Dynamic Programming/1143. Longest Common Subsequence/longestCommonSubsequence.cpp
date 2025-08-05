class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0, j = 0;
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));

        for (int i = text1.size() - 1; i >= 0; i--) {

            for (int j = text2.size() - 1; j >= 0; j--) {

                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {

                    int option1 = dp[i][j + 1];
                    int option2 = dp[i + 1][j];
                    dp[i][j] = max(option1, option2);
                }
            }
        }
        return dp[0][0];
    }
};
