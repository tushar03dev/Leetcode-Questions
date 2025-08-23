class Solution {
public:
    bool solve(vector<int>& nums, int index, int sum, int target, vector<vector<int>>& dp){
        if(sum == target){
            return true;
        }
        if(sum > target || index >= nums.size()){
            return false;
        }

        if(dp[index][sum] != -1){
            return dp[index][sum];
        }

        bool include = solve(nums,index+1, sum+nums[index], target,dp);
        bool exclude = solve(nums, index+1, sum, target,dp);

        dp[index][sum] = include || exclude;
        return dp[index][sum];
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int x : nums){
            totalSum += x;
        }
        if(totalSum & 1) return false;
        int index = 0;
        int sum = 0;
        vector<vector<int>> dp(nums.size()+1,vector<int>(totalSum/2 + 1,-1));

        bool ans = solve(nums, index, sum, totalSum/2,dp);
        return ans;
    }
};
