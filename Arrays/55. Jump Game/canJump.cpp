class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size()-1;
        int end = n;
        for(int i = n-1 ; i >= 0; i--){
            if(nums[i] + i >= end) end = i;
        }

        return end == 0;
    }
};
