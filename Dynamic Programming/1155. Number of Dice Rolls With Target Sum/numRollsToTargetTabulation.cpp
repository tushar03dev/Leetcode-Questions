class Solution {
public:
    long long MOD = 1e9 + 7;
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {

                int ans = 0;
                for (int l = 1; l <= k; l++) {
                    if (j - l >= 0) {
                        ans = (ans + dp[i - 1][j - l] % MOD) % MOD;
                    }
                }

                dp[i][j] = ans;
            }
        }

        return dp[n][target];
    }
};
