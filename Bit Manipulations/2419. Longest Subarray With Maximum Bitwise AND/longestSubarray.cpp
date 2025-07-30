class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);cout.tie(NULL);
        cout.tie(NULL);
        int candidate=nums[0];
        int finalCount=1,count=1;

        for(int i=1;i<nums.size();i++){
            if(nums[i] > candidate){
                candidate = nums[i];
                count =1;
                finalCount=1;
            }
            else if(nums[i] == candidate){
                count++;
            }
            else{
                count=0;
            }
            finalCount = max(finalCount,count);
        }

        return finalCount;
    }
};
