class Solution {
public:
    int solve(string &word1, string &word2, int i, int j, vector<vector<int>> &dp){
        // base case
        if(i == word1.size()) return word2.size()-j;
        if(j == word2.size()) return word1.size()-i;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]){
            dp[i][j] = solve(word1,word2,i+1,j+1,dp);
        } else{
            int replace = 1 + solve(word1,word2,i+1,j+1,dp);
            int insert = 1 + solve(word1, word2,i,j+1,dp);
            int remove = 1 + solve(word1,word2,i+1,j,dp);
            dp[i][j] = min(replace,min(insert,remove));
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int i =0,j=0;
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size(),-1));
        int ans =solve(word1,word2,i,j,dp);
        return ans;
    }
};
