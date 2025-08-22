class Solution {
public:
    int solve(int start, int end, vector<vector<int>>& dp){
        if(start >= end){
            return 0;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int ans = INT_MAX;
        for(int i = start; i <= end; i++ ){
            ans = min(ans, i + max(solve(start,i-1,dp),solve(i+1,end,dp)));
        }
        dp[start][end] = ans;
        return ans;
    }
    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int ans = solve(start,end,dp);
        return ans;
    }
};
