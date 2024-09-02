class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n=nums.size();
        int ans=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum == target){
                    ans=target;
                    return ans;
                }
                if(abs(sum-target)<abs(ans-target)){
                    ans=sum;
                }
                if(sum>target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
    }
};
