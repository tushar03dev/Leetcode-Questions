class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return;
        int i=0;
        int j=i;
        while(j<n){
            if(nums[i] != 0){
                i++;
                j++;
            }
            else if(nums[i] == 0 && nums[j] != 0){
                swap(nums[i],nums[j]);
            }
            else if((nums[i] ==0 && nums[j] ==0)){
                j++;
            }
        }
        
    }
};
