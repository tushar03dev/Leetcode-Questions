class Solution {
public:
    int rob(vector<int>& nums) {
        // Tabulation
        // step1
        vector<int> dp(nums.size(), -1);
        // step2
        dp[nums.size() - 1] = nums.back();
        // step3
        for (int i = nums.size() - 2; i >= 0; i--) {
            int temp = 0;
            if(i + 2  < nums.size()) temp = dp[i+2];
            int include = nums[i] + temp;
            int exclude = 0 + dp[i + 1];

            dp[i] = max(include, exclude);
        }
        return dp[0];
    }
};
