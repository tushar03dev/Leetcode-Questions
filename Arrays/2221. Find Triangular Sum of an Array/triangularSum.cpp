class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()  == 1) return nums[0];
        int temp = nums.size()-1;
        while(temp--){
            for(int i = 0; i <= temp ; i++) {
                nums[i] = (nums[i] + nums[i+1])%10;
            };
        }
        return nums[0];
    }
};
