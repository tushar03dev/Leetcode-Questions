class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int x : nums) {
            totalSum += x;
        }
        if (totalSum & 1)
            return false;
            
        int target = totalSum/2;    
        vector<int> curr(target+1,0);
        vector<int> next(target+1,0);
        curr[target] = 1;
        next[target] = 1;                  


        for(int index = nums.size()-1; index >= 0; index--){

            for (int sum = target - 1; sum >= 0; sum--) {

                bool include = 0;

                if(sum + nums[index] <= target){
                    include = next[sum + nums[index]];
                }    

                bool exclude = next[sum];

                curr[sum] = include || exclude;
            }

            next = curr;
        }

        return next[0];
    }
};
