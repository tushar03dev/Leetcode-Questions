class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum=1;
        int i=0;
        int count=0;
        int n1=nums.size();
        while(sum<=n){
        sum+=(i<n1 && nums[i]<=sum)?nums[i++]:sum;
        count++;
        }
        return count-i;
    }
};
