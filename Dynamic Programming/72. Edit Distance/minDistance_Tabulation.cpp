class Solution {
public:
    int minDistance(string word1, string word2) {
        int i = 0, j = 0;
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size()+1, 0));

        for(int col = 0; col <= word2.size(); col++){
            dp[word1.size()][col] = word2.size() - col;
        }

        for(int row = 0; row <= word1.size(); row++){
            dp[row][word2.size()] = word1.size() - row;
        }


        for (int i = word1.size()-1; i >= 0; i--) {
            for (int j = word2.size()-1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    int replace = 1 + dp[i + 1][j + 1];
                    int insert = 1 + dp[i][j + 1];
                    int remove = 1 + dp[i + 1][j];
                    dp[i][j] = min(replace, min(insert, remove));
                }
            }
        }
        return dp[0][0];
    }
};
