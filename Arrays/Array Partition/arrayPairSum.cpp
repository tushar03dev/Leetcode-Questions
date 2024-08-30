class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans=0;
        for(int i=0;i<n;i=i+2){
            ans+= nums[i];
        }
        return ans;
    }
};
