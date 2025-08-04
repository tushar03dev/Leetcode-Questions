class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Tabulation
        // step1 create dp
        vector<int> dp(amount + 1, INT_MAX);

        //step2 fill initial value manually
        dp[0] = 0;

        for (int value = 1; value <= amount; value++) {
            int mini = INT_MAX;
            for (int i = 0; i < coins.size(); i++) {
                if (value - coins[i] >= 0) {
                    int recAns = dp[value - coins[i]];
                    if (recAns != INT_MAX) {
                        int ans = 1 + recAns;
                        mini = min(mini, ans);
                    }
                }
            }
            dp[value] = mini;
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
