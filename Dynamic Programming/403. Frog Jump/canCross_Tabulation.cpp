class Solution {
public:

    bool canCross(vector<int>& stones) {

        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool>(n + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[n - 1][i] = true;
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = n; j >= 1; j--) {
                int target = stones[i] + j;
                int start = i + 1;
                int end = n - 1;
                bool can = false;

                while (start <= end) {
                    int mid = start + (end - start) / 2;
                    if (stones[mid] == target) {
                        bool option1 = dp[mid][j - 1];
                        bool option2 = dp[mid][j];
                        bool option3 = dp[mid][j + 1];

                        can = (option1 || option2) || option3;
                        break;
                    } else if (stones[mid] > target) {
                        end = mid - 1;
                    } else
                        start = mid + 1;
                }

                dp[i][j] = can;
            }
        }

        return dp[0][1];
    }
};
