class Solution {
public:
    int solve(vector<int>& arr, map<pair<int, int>, int>& maxi, int s, int e,vector<vector<int>>& dp) {
        if (s >= e) {
            return 0;
        }

        if(dp[s][e] != -1) return dp[s][e];

        int ans = INT_MAX;
        for (int i = s; i < e; i++) {
            ans = min(ans, (maxi[{s, i}] * maxi[{i + 1, e}] +
                               solve(arr, maxi, s, i, dp) +
                               solve(arr, maxi, i + 1, e, dp)));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }
    int mctFromLeafValues(vector<int>& arr) {
       
        map<pair<int, int>, int> maxi;
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        for (int i = 0; i < n; i++) {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }

        int start = 0;
        int ans = solve(arr, maxi, start, n - 1, dp);
        return ans;
    }
};
