class Solution {
public:
    long long MOD = 1e9 + 7;
    
    int numRollsToTarget(int n, int k, int target) {
        vector<int> curr (target+1,0);
        vector<int> prev (target+1, 0);
        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {

                int ans = 0;
                for (int l = 1; l <= k; l++) {
                    if (j - l >= 0) {
                        ans = (ans + prev[j - l] % MOD) % MOD;
                    }
                }

                curr[j] = ans;
            }
            prev = curr;
        }

        return curr[target];
    }
};
