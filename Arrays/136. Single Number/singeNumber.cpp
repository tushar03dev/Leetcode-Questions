class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int i=0;
        while(i<n){
            ans^=nums[i];
            i++;
        }
        return ans;
    }
};
