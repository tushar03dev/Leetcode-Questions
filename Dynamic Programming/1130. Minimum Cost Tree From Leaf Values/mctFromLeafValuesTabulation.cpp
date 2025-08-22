class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {

        map<pair<int, int>, int> maxi;
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }

        for (int s = n; s >= 0; s--) {
            for (int e = 0; e < n; e++) {

                if(s >= e) continue;

                int ans = INT_MAX;
                for (int i = s; i < e; i++) {
                    ans = min(ans, (maxi[{s, i}] * maxi[{i + 1, e}] + dp[s][i] + dp[i + 1][e]));
                }
                dp[s][e] = ans;
            }
        }
        return dp[0][n-1];
    }
};
