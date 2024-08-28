class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n=nums.size();
        int i=0;
        int oneCount=0;
        int loopCount=0;
        while(i<n){
            if(i==n-1 && nums[i] == 1){
                loopCount++;
                oneCount= max(oneCount,loopCount);
            }
            if(nums[i] == 1){
                loopCount++;
            }
            else{
                oneCount= max(oneCount,loopCount);
                loopCount=0;
            }
            i++;
        }
        return oneCount;    
    }   
};
