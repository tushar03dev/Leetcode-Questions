class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int x : nums) {
            totalSum += x;
        }
        if (totalSum & 1)
            return false;
        vector<vector<int>> dp(nums.size() + 2,
                               vector<int>(totalSum / 2 + 1, 0));

        for(int index = 0; index <= nums.size(); index++){
            dp[index][totalSum/2] = 1;
        }                       

        for(int index = nums.size()-1; index >= 0; index--){
            for (int sum = (totalSum / 2) - 1; sum >= 0; sum--) {
                bool include = 0;

                if(sum + nums[index] <= totalSum/2){
                    include = dp[index + 1][sum + nums[index]];
                }    

                bool exclude = dp[index + 1][sum];

                dp[index][sum] = include || exclude;
            }
        }

        return dp[0][0];
    }
};
