class Solution {
public:
    int solve(vector<int>& nums, int index, vector<int>& dp){
        // base case
        if(index >= nums.size()) return 0;

        // check for answer already in dp
        if(dp[index] != -1) return dp[index];

        int include =  nums[index] + solve(nums,index+2,dp);
        int exclude = 0 + solve(nums,index+1,dp);

        dp[index] = max(include,exclude);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int index = 0;
        vector<int> dp(nums.size(),-1);
        int ans = solve(nums,index,dp);
        return ans;
    }
};
