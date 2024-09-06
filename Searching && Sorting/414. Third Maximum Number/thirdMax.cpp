class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        else{
            sort(nums.begin(),nums.end());
            int i=n-2;
            int flag=1;
            int ans=nums.back();
            while(i>=0){
                if(ans > nums[i]){
                    ans=nums[i];
                    flag++;
                } 
                if(flag == 3){
                    return ans;
                } 
                i--;
            }
            if(flag !=3) return nums.back();
            return ans;
        }
    }
};
